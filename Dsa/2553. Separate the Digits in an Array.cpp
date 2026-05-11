// Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating them in the same order they appear in nums.

// To separate the digits of an integer is to get all the digits it has in the same order.

// For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].


class Solution {
public:

    vector<int> separateDigits(vector<int>& nums) {

        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            string s = to_string(nums[i]);

            for(int j = 0; j < s.length(); j++) {

                ans.push_back(s[j] - '0');
            }
        }

        return ans;
    }
};
