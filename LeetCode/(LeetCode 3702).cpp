// 3702. Longest Subsequence With Non-Zero Bitwise XOR

// You are given an integer array nums.

// Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            xr ^= x;

            if (x != 0) {
                hasNonZero = true;
            }
        }

        // All elements are zero
        if (!hasNonZero) {
            return 0;
        }

        // Entire array already has non-zero XOR
        if (xr != 0) {
            return n;
        }

        // Remove one non-zero element
        return n - 1;
    }
};