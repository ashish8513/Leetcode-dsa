//? Numbers with Given Digit Sum

// Given two integers n and sum, determine the number of n-digit positive integers whose digits add up to sum.

// An n-digit number cannot have leading zeros; that is, the first digit must be between 1 and 9.
// If there exist no n digit number with sum of digits equal to given sum, return -1.

class Solution {
public:
    vector<vector<int>> dp;

    int solve(int pos, int rem, int n)
    {
        if(pos == n)
            return rem == 0;

        if(dp[pos][rem] != -1)
            return dp[pos][rem];

        int ans = 0;

        int start = (pos == 0) ? 1 : 0;

        for(int d = start; d <= 9; d++)
        {
            if(rem >= d)
                ans += solve(pos + 1, rem - d, n);
        }

        return dp[pos][rem] = ans;
    }

    int countWays(int n, int sum)
    {
        if(sum > 9 * n || sum < 1)
            return -1;

        dp.assign(n + 1, vector<int>(sum + 1, -1));

        int ans = solve(0, sum, n);

        return ans == 0 ? -1 : ans;
    }
};