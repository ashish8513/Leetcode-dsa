// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n; i++){

            // skip duplicates
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while(left < right){

                int sum = nums[i] + nums[left] + nums[right];

                if(sum < 0){
                    left++;
                }

                else if(sum > 0){
                    right--;
                }

                else{

                    ans.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // skip duplicate left
                    while(left < right && nums[left] == nums[left - 1]){
                        left++;
                    }

                    // skip duplicate right
                    while(left < right && nums[right] == nums[right + 1]){
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};