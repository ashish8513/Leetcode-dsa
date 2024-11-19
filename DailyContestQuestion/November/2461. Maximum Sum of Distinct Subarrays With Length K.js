// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

// A subarray is a contiguous non-empty sequence of elements within an array.

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumSubarraySum = function(nums, k) {
    const n = nums.length;
    if (n < k) return 0; 

    let maxSum = 0;
    let currentSum = 0;
    let left = 0;
    const count = new Array(100001).fill(0);
    let distinctCount = 0;

    for (let right = 0; right < n; right++) {
        if (count[nums[right]] === 0) {
            distinctCount++; 
        }
        count[nums[right]]++;
        currentSum += nums[right];

        if (right >= k) {
            count[nums[left]]--;
            if (count[nums[left]] === 0) {
                distinctCount--; 
            }
            currentSum -= nums[left];
            left++;
        }

        if (right >= k - 1) {
            if (distinctCount === k) {
                maxSum = Math.max(maxSum, currentSum);
            }
        }
    }

    return maxSum === 0 ? 0 : maxSum;
};