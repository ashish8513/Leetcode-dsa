// You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:

// i + minJump <= j <= min(i + maxJump, s.length - 1), and
// s[j] == '0'.
// Return true if you can reach index s.length - 1 in s, or false otherwise.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

 
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        vector<bool> visited(n, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            // Try every possible jump
            for (int j = i + minJump; j <= min(i + maxJump, n - 1); j++) {

                // If reachable and not visited
                if (s[j] == '0' && !visited[j]) {

                    // Reached end
                    if (j == n - 1) {
                        return true;
                    }

                    visited[j] = true;
                    q.push(j);
                }
            }
        }

        return n == 1;
    }
};