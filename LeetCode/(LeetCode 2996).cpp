//? 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum

// You are given a 0-indexed array of integers nums.

// A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.

// Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Find sum of longest sequential prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        unordered_set<int> st(nums.begin(), nums.end());

        while (st.count(sum)) {
            sum++;
        }

        return sum;
    }
};