// The score of an array is defined as the product of its sum and its length.

// For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
// Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

// A subarray is a contiguous sequence of elements within an array.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function(nums, k) {
    let res = 0, partSum = 0, left = 0;

    for (let right = 0; right < nums.length; right++) {
        partSum += nums[right];
        while (partSum * (right - left + 1) >= k) {
            partSum -= nums[left++];
        }
        res += right - left + 1;
    }

    return res;
};