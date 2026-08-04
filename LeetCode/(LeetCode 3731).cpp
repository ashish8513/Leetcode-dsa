//? 3731. Find Missing Elements

// You are given an integer array nums consisting of unique integers.

// Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.

// The smallest and largest integers of the original range are still present in nums.

// Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = 1; i < nums.size(); i++) {
            for (int x = nums[i - 1] + 1; x < nums[i]; x++) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};