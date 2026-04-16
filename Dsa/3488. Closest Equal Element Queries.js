// You are given a circular array nums and an array queries.

// For each query i, you have to find the following:

// The minimum distance between the element at index queries[i] and any other index j in the circular array, where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1.
// Return an array answer of the same size as queries, where answer[i] represents the result for query i.

/**
 * @param {number[]} nums
 * @param {number[]} queries
 * @return {number[]}
 */
var solveQueries = function(nums, queries) {
    const n = nums.length;
    const map = new Map();

    // Step 1: store indices
    for (let i = 0; i < n; i++) {
        if (!map.has(nums[i])) map.set(nums[i], []);
        map.get(nums[i]).push(i);
    }

    // Step 2: precompute answer for each index
    const ans = new Array(n).fill(-1);

    for (let arr of map.values()) {
        let m = arr.length;
        if (m === 1) continue;

        for (let i = 0; i < m; i++) {
            let curr = arr[i];
            let prev = arr[(i - 1 + m) % m];
            let next = arr[(i + 1) % m];

            let d1 = Math.abs(curr - prev);
            let d2 = Math.abs(curr - next);

            ans[curr] = Math.min(
                Math.min(d1, n - d1),
                Math.min(d2, n - d2)
            );
        }
    }

    // Step 3: answer queries in O(1)
    return queries.map(q => ans[q]);
};
