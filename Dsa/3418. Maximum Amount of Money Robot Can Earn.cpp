// You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). The robot can move either right or down at any point in time.

// The grid contains a value coins[i][j] in each cell:

// If coins[i][j] >= 0, the robot gains that many coins.
// If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.
// The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them from stealing coins in those cells.

// Note: The robot's total coins can be negative.

// Return the maximum profit the robot can gain on the route

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        const int NEG = -1e9;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, NEG)));

        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0; 
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k < 3; k++) {
                    int bestPrev = NEG;
                    if (i > 0) bestPrev = max(bestPrev, dp[i - 1][j][k]);
                    if (j > 0) bestPrev = max(bestPrev, dp[i][j - 1][k]);

                    if (bestPrev != NEG) {
                        dp[i][j][k] = max(dp[i][j][k], bestPrev + coins[i][j]);
                    }

                    if (coins[i][j] < 0 && k > 0) {
                        int bestPrevNeutral = NEG;
                        if (i > 0) bestPrevNeutral = max(bestPrevNeutral, dp[i - 1][j][k - 1]);
                        if (j > 0) bestPrevNeutral = max(bestPrevNeutral, dp[i][j - 1][k - 1]);

                        if (bestPrevNeutral != NEG) {
                            dp[i][j][k] = max(dp[i][j][k], bestPrevNeutral);
                        }
                    }
                }
            }
        }

        return max({dp[m - 1][n - 1][0], dp[m - 1][n - 1][1], dp[m - 1][n - 1][2]});
    }
};
