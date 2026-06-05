// You are given two integers num1 and num2 representing an inclusive range [num1, num2].

// The waviness of a number is defined as the total count of its peaks and valleys:

// A digit is a peak if it is strictly greater than both of its immediate neighbors.
// A digit is a valley if it is strictly less than both of its immediate neighbors.
// The first and last digits of a number cannot be peaks or valleys.
// Any number with fewer than 3 digits has a waviness of 0.
// Return the total sum of waviness for all numbers in the range [num1, num2].

class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;
    Node dp[20][11][11][2];
    bool vis[20][11][11][2];

    Node dfs(int pos, int prev2, int prev1, int started, bool tight) {
        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][prev2][prev1][started]) {
            return dp[pos][prev2][prev1][started];
        }

        int limit = tight ? s[pos] - '0' : 9;
        Node ans = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node child = dfs(pos + 1, 10, 10, 0, ntight);
                ans.cnt += child.cnt;
                ans.sum += child.sum;
            }
            else if (!started) {
                Node child = dfs(pos + 1, 10, d, 1, ntight);
                ans.cnt += child.cnt;
                ans.sum += child.sum;
            }
            else {
                int add = 0;

                if (prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d)) {
                        add = 1;
                    }
                }

                Node child = dfs(pos + 1, prev1, d, 1, ntight);

                ans.cnt += child.cnt;
                ans.sum += child.sum + 1LL * add * child.cnt;
            }
        }

        if (!tight) {
            vis[pos][prev2][prev1][started] = true;
            dp[pos][prev2][prev1][started] = ans;
        }

        return ans;
    }

    long long solve(long long x) {
        if (x < 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, 0, true).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
}; 