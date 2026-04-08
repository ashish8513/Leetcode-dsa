// You are given an integer array nums of length n and a 2D integer array queries of size q, where queries[i] = [li, ri, ki, vi].

// For each query, you must apply the following operations in order:

// Set idx = li.
// While idx <= ri:
// Update: nums[idx] = (nums[idx] * vi) % (109 + 7)
// Set idx += ki.
// Return the bitwise XOR of all elements in nums after processing all queries.

class Solution {
    static const int mod = 1e9 + 7;

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            for (int i = l; i <= r; i += k) {
                nums[i] = (1LL * nums[i] * v) % mod;
            }
        }

        int res = 0;
        for (int x : nums) {
            res ^= x;
        }

        return res;
    }
};
