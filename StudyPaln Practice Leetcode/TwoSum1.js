// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let n=nums.length;
    for(let i=0;i<=n-2;i++){
        for(let j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                return [i,j]
            }
        }
    }
};