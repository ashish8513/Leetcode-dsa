// A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot receives an array of integers commands, which represents a sequence of moves that it needs to execute. There are only three possible types of instructions the robot can receive:

// -2: Turn left 90 degrees.
// -1: Turn right 90 degrees.
// 1 <= k <= 9: Move forward k units, one unit at a time.
// Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, it will stay in its current location (on the block adjacent to the obstacle) and move onto the next command.

// Return the maximum squared Euclidean distance that the robot reaches at any point in its path (i.e. if the distance is 5, return 25).

// Note:

// There can be an obstacle at (0, 0). If this happens, the robot will ignore the obstacle until it has moved off the origin. However, it will be unable to return to (0, 0) due to the obstacle.
// North means +Y direction.
// East means +X direction.
// South means -Y direction.
// West means -X direction.


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;
        for (auto &o: obstacles) {
            string str = to_string(o[0]) + "#" + to_string(o[1]);
            obs.insert(str);
        }

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int x = 0, y = 0;
        int dir = 0;       
        int maxDist = 0;

        for (int cmd: commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            }
            else if (cmd == -2) {
                dir = (dir + 3) % 4;
            }
            else {
                for (int step = 0; step < cmd; step++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    string key = to_string(nx) + "#" + to_string(ny);

                    if (obs.count(key))
                        break;

                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        return maxDist;
    }
};
