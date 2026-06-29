//? Max Dot Product with 0 Insertions

// Given two arrays a[] and b[] of positive integers of size n and m respectively, where m ≤ n.  You are allowed to insert zeros anywhere into the second array b so that its length becomes equal to n.

// The dot product of two arrays of equal length n is defined as: a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1].
// Return the maximum possible dot product of the two arrays.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {

                // Skip current element of a (insert 0)
                dp[i][j] = dp[i - 1][j];

                // Match a[i-1] with b[j-1]
                if (dp[i - 1][j - 1] != INT_MIN) {
                    dp[i][j] = max(dp[i][j],
                                   dp[i - 1][j - 1] + a[i - 1] * b[j - 1]);
                }
            }
        }

        return dp[n][m];
    }
}; 