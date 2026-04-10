// You are given an integer array nums.

// A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].

// The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.

// Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDistance = function(nums) {
    const map = new Map();

    // Step 1: store indices
    for (let i = 0; i < nums.length; i++) {
        if (!map.has(nums[i])) {
            map.set(nums[i], []);
        }
        map.get(nums[i]).push(i);
    }

    let ans = Infinity;

    // Step 2: process each value
    for (let indices of map.values()) {
        if (indices.length < 3) continue;

        // Step 3: check triplets
        for (let i = 0; i <= indices.length - 3; i++) {
            let minIndex = indices[i];
            let maxIndex = indices[i + 2];

            let distance = 2 * (maxIndex - minIndex);
            ans = Math.min(ans, distance);
        }
    }

    return ans === Infinity ? -1 : ans;
};
