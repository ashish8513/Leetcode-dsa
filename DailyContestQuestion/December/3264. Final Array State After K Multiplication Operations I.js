// You are given an integer array nums, an integer k, and an integer multiplier.

// You need to perform k operations on nums. In each operation:

// Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
// Replace the selected minimum value x with x * multiplier.
// Return an integer array denoting the final state of nums after performing all k operations.

/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} multiplier
 * @return {number[]}
 */

var getFinalState = function(nums, k, multiplier) {
    let i = 0;
    
    while(i < k) {
        let minValue = Math.min(...nums); // find the min value
        let newValue = minValue * multiplier; // multiple it
        let minIndex = nums.indexOf(minValue);  // find the min idx
        if (minIndex !== -1) { 
            nums[minIndex] = newValue; // replace it
        }
        i++;
    }
    return nums;
};