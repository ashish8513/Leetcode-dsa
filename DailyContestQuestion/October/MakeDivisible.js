// 1590. Make Sum Divisible by P
// Solved
// Medium
// Topics
// Companies
// Hint
// Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

// Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

// A subarray is defined as a contiguous block of elements in the array.
/**
 * @param {number[]} nums
 * @param {number} p
 * @return {number}
 */
function minSubarray(nums, p) {
    const totalSum = nums.reduce((a, b) => a + b, 0);
    const target = totalSum % p;

    if (target === 0) return 0;

    const prefixMod = new Map();
    prefixMod.set(0, -1);
    let prefixSum = 0;
    let minLength = nums.length;

    for (let i = 0; i < nums.length; i++) {
        prefixSum = (prefixSum + nums[i]) % p;
        let need = (prefixSum - target + p) % p;

        if (prefixMod.has(need)) {
            minLength = Math.min(minLength, i - prefixMod.get(need));
        }

        prefixMod.set(prefixSum, i);
    }

    return minLength < nums.length ? minLength : -1;
}
