// You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

// You can perform the following operation at most maxOperations times:

// Take any bag of balls and divide it into two new bags with a positive number of balls.
// For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
// Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

// Return the minimum possible penalty after performing the operations.

/**
 * @param {number[]} nums
 * @param {number} maxOperations
 * @return {number}
 */
var minimumSize = function(nums, maxOperations) {
    let low = 1, high = 10 ** 9, mid;
 while (low < high) {
     mid = (low + high) >>> 1;
     nums.reduce((acc, curr) => acc + Math.ceil(curr / mid - 1), 0) > maxOperations
         ? (low = mid + 1)
         : (high = mid)
 }
 return low;
};