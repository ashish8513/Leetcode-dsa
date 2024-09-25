// Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function(nums) {
    let result = 0;
nums.sort((a, b) => a-b);
for(let i = nums.length - 2; i >= 0; i -= 2) {
    result += nums[i];
}
return result;
};