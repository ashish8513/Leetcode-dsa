//? Rat Maze With Multiple Jumps

// Given a matrix mat[][] of size n × n, where mat[i][j] represents the maximum number of steps a rat can jump either forward (right) or downward from that cell, find a path for the rat to reach from the top-left cell (0, 0) to the bottom-right cell (n - 1, n - 1). A cell containing 0 is blocked and cannot be used in the path. It is guaranteed that the cell mat[n-1][n-1] is not 0.

// Return an n × n matrix where 1 represents the cells included in the path and 0 represents the remaining cells. If no valid path exists, return [[-1]].

// Note: If multiple valid paths exist, choose the path with the shortest possible jumps first. For the same jump length, moving forward (right) should be preferred over moving downward.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& mat,
             vector<vector<int>>& ans,
             vector<vector<int>>& dp, int n) {

        if (i == n - 1 && j == n - 1) {
            ans[i][j] = 1;
            return true;
        }

        if (mat[i][j] == 0) return false;

        if (dp[i][j] == 0) return false; // already known dead end

        ans[i][j] = 1;

        int jump = mat[i][j];

        for (int k = 1; k <= jump; k++) {

            // Right first
            if (j + k < n) {
                if (dfs(i, j + k, mat, ans, dp, n))
                    return true;
            }

            // Down second
            if (i + k < n) {
                if (dfs(i + k, j, mat, ans, dp, n))
                    return true;
            }
        }

        ans[i][j] = 0;
        dp[i][j] = 0; // mark impossible
        return false;
    }

    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();

        if (mat[0][0] == 0)
            return {{-1}};

        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<int>> dp(n, vector<int>(n, 1));

        if (dfs(0, 0, mat, ans, dp, n))
            return ans;

        return {{-1}};
    }
};