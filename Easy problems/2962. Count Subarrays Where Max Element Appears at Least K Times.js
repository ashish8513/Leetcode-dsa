// You are given an integer array nums and a positive integer k.

// Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

// A subarray is a contiguous sequence of elements within an array.

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function (nums, k) {
    const n = nums.length;
    if (n < k) return 0;

    // find global maximum M
    let M = -Infinity;
    for (let v of nums) {
        if (v > M) M = v;
    }

    // total subarrays
    const total = (n * (n + 1)) / 2;

    // count subarrays with fewer than k occurrences of M
    let bad = 0, left = 0, count = 0;
    for (let right = 0; right < n; ++right) {
        if (nums[right] === M) count++;
        while (count >= k) {
            if (nums[left] === M) count--;
            left++;
        }
        bad += (right - left + 1);
    }
    return total - bad;
};