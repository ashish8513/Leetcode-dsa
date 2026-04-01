//  There are n 1-indexed robots, each having a position on a line, health, and movement direction.

// You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.

// All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.

// If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.

// Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final health of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.

// Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.

// Note: The positions may be unsorted.


class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<vector<int>> robots;
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        sort(robots.begin(), robots.end());

        stack<int> st; 

        for (int i = 0; i < n; i++) {
            if (robots[i][2] == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && robots[i][1] > 0) {
                    int j = st.top(); 

                    if (robots[j][1] < robots[i][1]) {
                        robots[i][1]--;
                        robots[j][1] = 0;
                        st.pop();
                    } 
                    else if (robots[j][1] > robots[i][1]) {
                        robots[j][1]--;
                        robots[i][1] = 0;
                    } 
                    else {
                        robots[j][1] = 0;
                        robots[i][1] = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<int> ansByIndex(n, 0);
        for (int i = 0; i < n; i++) {
            if (robots[i][1] > 0) {
                ansByIndex[robots[i][3]] = robots[i][1];
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (ansByIndex[i] > 0) {
                ans.push_back(ansByIndex[i]);
            }
        }

        return ans;
    }
};
