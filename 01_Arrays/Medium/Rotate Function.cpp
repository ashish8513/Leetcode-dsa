// 396. Rotate Function
// Medium
// Topics
// premium lock icon
// Companies
// You are given an integer array nums of length n.

// Assume arrk to be an array obtained by rotating nums by k positions clock-wise. We define the rotation function F on nums as follow:

// F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
// Return the maximum value of F(0), F(1), ..., F(n-1).

// The test cases are generated so that the answer fits in a 32-bit integer.

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0;
        long long f = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += 1LL * i * nums[i];
        }

        long long ans = f;

        for (int k = 1; k < n; k++) {
            f = f + sum - 1LL * n * nums[n - k];
            ans = max(ans, f);
        }

        return (int)ans;
    }
};