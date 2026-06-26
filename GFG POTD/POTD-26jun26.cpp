//? Count Matching Subsequences
// Given two strings, s1 and s2, count the number of subsequences of string s1 equal to string s2.
// Return the total count modulo 1e9+7.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int countWays(string &s1, string &s2) {
        const int MOD = 1e9 + 7;

        int n = s1.size();
        int m = s2.size();

        vector<long long> dp(m + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = (dp[j] + dp[j - 1]) % MOD;
                }
            }
        }

        return dp[m];
    }
};