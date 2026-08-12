//? Adventure in a Maze

// Given a maze represented as an n x n grid, grid[][], using 0-based indexing. Each cell contains one of the values 1, 2, or 3, which determines the direction(s) you are allowed to move from that cell:

// 1 - you may move Right only.
// 2 - you may move Down only.
// 3 - you may move Right or Down (both directions are available).
// You start at the top-left cell (0, 0) (the Entry) and must reach the bottom-right cell (n-1, n-1) (the Exit), following the movement rule of each cell you pass through. You are never allowed to move outside the boundaries of the grid.

// The Adventure of a path is the sum of the values of all cells visited along that path (including both the entry and exit cells).

// Find the total number of distinct valid paths from Entry to Exit, and among all such paths, the maximum possible Adventure. Return the answer as [totalPaths, maxAdventure].

// Note: Return totalPaths modulo 109 + 7, maxAdventure needs no modulo, as it stays small regardless of grid size.

class Solution {
public:
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        const int MOD = 1e9 + 7;

        vector<vector<long long>> paths(n, vector<long long>(n, 0));
        vector<vector<long long>> adventure(n, vector<long long>(n, -1));

        // Starting cell
        paths[0][0] = 1;
        adventure[0][0] = grid[0][0];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // Current cell unreachable hai
                if (paths[i][j] == 0)
                    continue;

                // Move Right
                if ((grid[i][j] == 1 || grid[i][j] == 3) &&
                    j + 1 < n) {

                    paths[i][j + 1] =
                        (paths[i][j + 1] + paths[i][j]) % MOD;

                    adventure[i][j + 1] =
                        max(adventure[i][j + 1],
                            adventure[i][j] + grid[i][j + 1]);
                }

                // Move Down
                if ((grid[i][j] == 2 || grid[i][j] == 3) &&
                    i + 1 < n) {

                    paths[i + 1][j] =
                        (paths[i + 1][j] + paths[i][j]) % MOD;

                    adventure[i + 1][j] =
                        max(adventure[i + 1][j],
                            adventure[i][j] + grid[i + 1][j]);
                }
            }
        }

        // Exit unreachable
        if (paths[n - 1][n - 1] == 0)
            return {0, 0};

        return {
            (int)paths[n - 1][n - 1],
            (int)adventure[n - 1][n - 1]
        };
    }
};