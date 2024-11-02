// Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.

// An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.

// The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).

/**
 * @param {number[]} nums
 * @return {number}
 */
function countMaxOrSubsets(nums) {
    const n = nums.length;
    let res = 0;
    let max = 0;
    const dfs = (i, currOr) => {
        if (i === n) return;

        for (let j = i; j < n; j++) {
            const newOr = currOr | nums[j];

            if (newOr > max) {
                max = newOr;
                res = 1;
            } else if (newOr === max) {
                res++;
            }

            dfs(j + 1, newOr);
        }
    };

    dfs(0, 0);
    return res;
}
