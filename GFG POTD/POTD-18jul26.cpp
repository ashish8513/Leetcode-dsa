//? Cut Matrix

// Given a matrix of 0s and 1s and an integer k, divide the matrix into k pieces such that each piece has at least one 1 in it. A cut can be made in the following way:

// Choose a direction: vertical or horizontal.
// Choose an index to cut the matrix into two pieces.
// If the cut is horizontal, only the bottom part can be cut further.
// If the cut is vertical, only the right part can be cut further.
// Return the number of different ways to divide the matrix modulo 1e9 + 7.

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int n, m;
    vector<vector<int>> suf;
    vector<vector<vector<int>>> dp;

    int solve(int r, int c, int cuts) {
        if (suf[r][c] == 0) return 0;      // no 1 present
        if (cuts == 1) return 1;           // last piece

        if (dp[r][c][cuts] != -1)
            return dp[r][c][cuts];

        long long ans = 0;

        // Horizontal cuts
        for (int nr = r + 1; nr < n; nr++) {
            // upper part has at least one 1
            if (suf[r][c] - suf[nr][c] > 0) {
                ans = (ans + solve(nr, c, cuts - 1)) % MOD;
            }
        }

        // Vertical cuts
        for (int nc = c + 1; nc < m; nc++) {
            // left part has at least one 1
            if (suf[r][c] - suf[r][nc] > 0) {
                ans = (ans + solve(r, nc, cuts - 1)) % MOD;
            }
        }

        return dp[r][c][cuts] = ans;
    }

    int findWays(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        m = matrix[0].size();

        suf.assign(n + 1, vector<int>(m + 1, 0));

        // Build suffix sum of number of 1's
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                suf[i][j] = matrix[i][j]
                          + suf[i + 1][j]
                          + suf[i][j + 1]
                          - suf[i + 1][j + 1];
            }
        }

        dp.assign(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));

        return solve(0, 0, k);
    }
};