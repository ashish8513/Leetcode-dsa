// You are given an m x n integer matrix grid and an integer k.

// For every contiguous k x k submatrix of grid, compute the minimum absolute difference between any two distinct values within that submatrix.

// Return a 2D array ans of size (m - k + 1) x (n - k + 1), where ans[i][j] is the minimum absolute difference in the submatrix whose top-left corner is (i, j) in grid.

// Note: If all elements in the submatrix have the same value, the answer will be 0.

// A submatrix (x1, y1, x2, y2) is a matrix that is formed by choosing all cells matrix[x][y] where x1 <= x <= x2 and y1 <= y <= y2.


class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                vector<int> vals;
                vals.reserve(k * k);

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        vals.push_back(grid[x][y]);
                    }
                }

                sort(vals.begin(), vals.end());

                int minDiff = INT_MAX;

                for (int t = 1; t < vals.size(); t++) {
                    if (vals[t] == vals[t - 1]) continue; 
                    minDiff = min(minDiff, vals[t] - vals[t - 1]);
                }

                ans[i][j] = (minDiff == INT_MAX ? 0 : minDiff);
            }
        }

        return ans;
    }
};
