// Numbers Without d as Digit


// Given a number n, count the numbers from 1 to n that don’t contain digit d in their decimal representation.

class Solution {
public:
    int countWithout(int n, int d) {
        string s = to_string(n);
        int len = s.size();

        long long dp[20][2][2];
        memset(dp, -1, sizeof(dp));

        function<long long(int, int, int)> solve =
            [&](int pos, int tight, int started) -> long long {

            if (pos == len)
                return started ? 1 : 0;

            long long &res = dp[pos][tight][started];

            if (res != -1)
                return res;

            res = 0;

            int limit = tight ? s[pos] - '0' : 9;

            for (int digit = 0; digit <= limit; digit++) {

                if (digit == d && (started || digit != 0))
                    continue;

                int newTight = tight && (digit == s[pos] - '0');
                int newStarted = started || digit != 0;

                res += solve(pos + 1, newTight, newStarted);
            }

            return res;
        };

        return solve(0, 1, 0);
    }
}; 