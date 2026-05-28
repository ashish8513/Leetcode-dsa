
// Code
// Testcase
// Testcase
// Test Result
// Note
// Note
// Leet
// 18. 4Sum
// Medium
// Topics
// premium lock icon
// Companies
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            // skip duplicate i
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for(int j = i + 1; j < n; j++) {

                // skip duplicate j
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;

                while(left < right) {

                    long long sum =
                    (long long)nums[i] +
                    nums[j] +
                    nums[left] +
                    nums[right];

                    if(sum < target) {
                        left++;
                    }

                    else if(sum > target) {
                        right--;
                    }

                    else {

                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        left++;
                        right--;

                        // skip duplicate left
                        while(left < right &&
                              nums[left] == nums[left - 1]) {
                            left++;
                        }

                        // skip duplicate right
                        while(left < right &&
                              nums[right] == nums[right + 1]) {
                            right--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};