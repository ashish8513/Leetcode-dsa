//? High Effort vs Low Effort

// Given two integer arrays h[] and l[], where h[i] and l[i] denote the number of tasks that can be completed on the i-th day by performing a high-effort task and a low-effort task, respectively.

// For each day, you may choose exactly one of the following:

// Perform no task.
// Perform a low-effort task.
// Perform a high-effort task, which can only be performed on the first day or if no task was performed on the previous day.
// Return the maximum total number of tasks that can be completed over all days.


class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();

        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            dp[i] = dp[i - 1] + 0;

            dp[i] = max(dp[i], dp[i - 1] + l[i - 1]);

            if (i == 1) {
                dp[i] = max(dp[i], h[i - 1]);
            } 
            else {
                dp[i] = max(dp[i], dp[i - 2] + h[i - 1]);
            }
        }

        return dp[n];
    }
};