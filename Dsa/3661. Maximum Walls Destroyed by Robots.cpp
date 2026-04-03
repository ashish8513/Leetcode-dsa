// There is an endless straight line populated with some robots and walls. You are given integer arrays robots, distance, and walls:
// robots[i] is the position of the ith robot.
// distance[i] is the maximum distance the ith robot's bullet can travel.
// walls[j] is the position of the jth wall.
// Every robot has one bullet that can either fire to the left or the right at most distance[i] meters.

// A bullet destroys every wall in its path that lies within its range. Robots are fixed obstacles: if a bullet hits another robot before reaching a wall, it immediately stops at that robot and cannot continue.

// Return the maximum number of unique walls that can be destroyed by the robots.

// Notes:

// A wall and a robot may share the same position; the wall can be destroyed by the robot at that position.
// Robots are not destroyed by bullets.

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,vector<int>& walls) {
        int n = robots.size();
        int pos1, pos2, pos3, leftPos, rightPos;
        vector<int> left(n, 0), right(n, 0), num(n, 0);
        unordered_map<int, int> robotsToDistance;
        for (int i = 0; i < n; i++) {
            robotsToDistance[robots[i]] = distance[i];
        }
        sort(robots.begin(), robots.end());
        sort(walls.begin(), walls.end());
        for (int i = 0; i < n; i++) {
            pos1 = upper_bound(walls.begin(), walls.end(), robots[i]) -
                   walls.begin();
            if (i >= 1) {
                leftPos =
                    lower_bound(walls.begin(), walls.end(),
                    max(robots[i] - robotsToDistance[robots[i]],
                    robots[i - 1] + 1)) -
                    walls.begin();
            } else {
                leftPos = lower_bound(walls.begin(), walls.end(),
                robots[i] - robotsToDistance[robots[i]]) -
                walls.begin();
            }
            left[i] = pos1 - leftPos;
            if (i < n - 1) {
                rightPos =
                    upper_bound(walls.begin(), walls.end(),
                    min(robots[i] + robotsToDistance[robots[i]],
                    robots[i + 1] - 1)) -
                    walls.begin();
            } else {
                rightPos =
                    upper_bound(walls.begin(), walls.end(),
                    robots[i] + robotsToDistance[robots[i]]) -
                    walls.begin();
            }
            pos2 = lower_bound(walls.begin(), walls.end(), robots[i]) -
                   walls.begin();
            right[i] = rightPos - pos2;
            if (i == 0) {
                continue;
            }
            pos3 = lower_bound(walls.begin(), walls.end(), robots[i - 1]) -
            walls.begin();
            num[i] = pos1 - pos3;
        }
        int subLeft, subRight, currentLeft, currentRight;
        subLeft = left[0];
        subRight = right[0];
        for (int i = 1; i < n; i++) {
            currentLeft =
                max(subLeft + left[i], subRight - right[i - 1] +
                min(left[i] + right[i - 1], num[i]));
            currentRight = max(subLeft + right[i], subRight + right[i]);
            subLeft = currentLeft;
            subRight = currentRight;
        }
        return max(subLeft, subRight);
    }
};
