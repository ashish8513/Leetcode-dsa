/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.
var search = function(nums, target) {
    let lo = 0;
    let hi = nums.length - 1;
    while(lo <= hi) {
        let mid = Math.floor((lo + hi) / 2);
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) {
            // remove left half
            lo = mid + 1;
        } else {
            // remove right half
            hi = mid - 1;
        }
    }
    return -1;
};

module.exports = search;