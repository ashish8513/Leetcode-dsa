//? Maximum Reachable Index Difference


// Given a string s containing lowercase English alphabets.

// Start from any index containing the character 'a' and perform jump operations.
// In each jump operation, move to any index on the right side whose character is the immediate next letter of the current character in the alphabet (i.e., 'a' to 'b', 'b' to 'c', 'c' to 'd', and so on). 
// Continue performing jumps until no further jump is possible.
// Find the maximum possible difference between the starting index and the ending index. If it is not possible to choose a starting index, return -1.

class Solution {
public:
    int maxIndexDifference(string &s) {
        int n = s.size();

        vector<int> dp(n);
        vector<int> last(26, -1);

        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            if (c == 25) {
                dp[i] = i;
            } else if (last[c + 1] != -1) {
                dp[i] = dp[last[c + 1]];
            } else {
                dp[i] = i;
            }

            last[c] = i;
        }

        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                ans = max(ans, dp[i] - i);
        }

        return ans;
    }
};