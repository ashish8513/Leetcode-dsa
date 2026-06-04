// You are given two integers num1 and num2 representing an inclusive range [num1, num2].

// The waviness of a number is defined as the total count of its peaks and valleys:

// A digit is a peak if it is strictly greater than both of its immediate neighbors.
// A digit is a valley if it is strictly less than both of its immediate neighbors.
// The first and last digits of a number cannot be peaks or valleys.
// Any number with fewer than 3 digits has a waviness of 0.
// Return the total sum of waviness for all numbers in the range [num1, num2].
 
class Solution {
    struct Node {
        long long cnt;
        long long wav;
        Node(long long c = 0, long long w = 0) : cnt(c), wav(w) {}
    };

    string s;
    Node dp[20][2][2][11][11];
    bool vis[20][2][2][11][11];

    Node dfs(int pos, int tight, int started, int prev2, int prev1) {
        if (pos == s.size()) {
            return Node(1, 0);
        }

        if (!tight && vis[pos][tight][started][prev2 + 1][prev1 + 1])
            return dp[pos][tight][started][prev2 + 1][prev1 + 1];

        int lim = tight ? s[pos] - '0' : 9;

        Node ans;

        for (int d = 0; d <= lim; d++) {
            int ntight = tight && (d == lim);

            if (!started && d == 0) {
                Node child = dfs(pos + 1, ntight, 0, -1, -1);
                ans.cnt += child.cnt;
                ans.wav += child.wav;
            }
            else if (!started) {
                Node child = dfs(pos + 1, ntight, 1, -1, d);
                ans.cnt += child.cnt;
                ans.wav += child.wav;
            }
            else {
                long long add = 0;

                if (prev2 != -1) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                Node child = dfs(pos + 1, ntight, 1, prev1, d);

                ans.cnt += child.cnt;
                ans.wav += child.wav + add * child.cnt;
            }
        }

        if (!tight) {
            vis[pos][tight][started][prev2 + 1][prev1 + 1] = true;
            dp[pos][tight][started][prev2 + 1][prev1 + 1] = ans;
        }

        return ans;
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 1, 0, -1, -1).wav;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
}; 