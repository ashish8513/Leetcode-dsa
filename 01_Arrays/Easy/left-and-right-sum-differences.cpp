// You are given a 0-indexed integer array nums of size n.

// Define two arrays leftSum and rightSum where:

// leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
// rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
// Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0;

        for (int x : nums) {
            totalSum += x;
        }

        vector<int> ans(nums.size());
        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            totalSum -= nums[i];   // right sum

            ans[i] = abs(leftSum - totalSum);

            leftSum += nums[i];
        }

        return ans;
    }
};