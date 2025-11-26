// You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.

// Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 109 + 7.




/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number}
 */
var numberOfPaths = function (grid, k) {
    const mod = 1e9 + 7;
    const m = grid.length, n = grid[0].length;
    // initialization of dp 2D array
    let dp = Array.from({ length: m }, () =>
        Array.from({ length: n }, () => Array(k).fill(0))
    );

    dp[0][0][grid[0][0] % k] = 1;

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {

            if (i === 0 && j === 0) continue;

            for (let r = 0; r < k; r++) {
                let newR = (r + grid[i][j]) % k;

                if (i > 0)
                    dp[i][j][newR] = (dp[i][j][newR] + dp[i - 1][j][r]) % mod;
                if (j > 0)
                    dp[i][j][newR] = (dp[i][j][newR] + dp[i][j - 1][r]) % mod;
            }
        }
    }

    return dp[m - 1][n - 1][0];

};
