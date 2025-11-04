// You are given an array nums of n integers and two integers k and x.

// The x-sum of an array is calculated by the following procedure:

// Count the occurrences of all elements in the array.
// Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
// Calculate the sum of the resulting array.
// Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

// Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].



/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findXSum = function (nums, k, x) {
    const n = nums.length - k + 1;
    const arr = new Array(n);

    for (let i = 0; i < n; i++) {
        const sub = nums.slice(i, i + k);
        const freq = new Map();

        for (const num of sub) {
            freq.set(num, (freq.get(num) || 0) + 1);
        }

        const top = [...freq.entries()]
            .sort((a, b) => b[1] - a[1] || b[0] - a[0])
            .slice(0, x);

        let sum = 0;
        for (const [num, count] of top) sum += num * count;
        arr[i] = sum;
    }

    return arr;
};