// You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

// Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
// Return the total number of continuous subarrays.

// A subarray is a contiguous non-empty sequence of elements within an array.


/**
 * @param {number[]} nums
 * @return {number}
 */

var continuousSubarrays = function(nums) {
    let total = 0;
    let left = 0;
    let maxDeque = [];
    let minDeque = [];
  
    for (let right = 0; right < nums.length; right++) {
      while (maxDeque.length && nums[maxDeque[maxDeque.length - 1]] <= nums[right]) {
        maxDeque.pop();
      }
      maxDeque.push(right);
  
      while (minDeque.length && nums[minDeque[minDeque.length - 1]] >= nums[right]) {
        minDeque.pop();
      }
      minDeque.push(right);
  
      while (nums[maxDeque[0]] - nums[minDeque[0]] > 2) {
        if (maxDeque[0] === left) maxDeque.shift();
        if (minDeque[0] === left) minDeque.shift();
        left++;
      }
  
      total += right - left + 1;
    }
  
    return total;
  };