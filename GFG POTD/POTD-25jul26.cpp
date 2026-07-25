// Max Sum Square Sub-Matrix of Size k

// Given a n × n grid mat[][] of integers where values can be negative, find the maximum sum among all possible k × k sub-grids.

class Solution {
public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();

        vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i - 1][j - 1]
                             + prefix[i - 1][j]
                             + prefix[i][j - 1]
                             - prefix[i - 1][j - 1];
            }
        }

        int ans = INT_MIN;

        for (int i = k; i <= n; i++) {
            for (int j = k; j <= n; j++) {

                int sum = prefix[i][j]
                        - prefix[i - k][j]
                        - prefix[i][j - k]
                        + prefix[i - k][j - k];

                ans = max(ans, sum);
            }
        }

        return ans;
    }
}; 