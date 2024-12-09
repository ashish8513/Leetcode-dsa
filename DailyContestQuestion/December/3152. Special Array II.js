// An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

// You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
// subarray
//  nums[fromi..toi] is special or not.

// Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {boolean[]}
 */
var isArraySpecial = function(nums, queries) {
    let prevGood = 0;
let ans = [0]
for (let i = 1; i < nums.length; i++) {
    if ((nums[i - 1] + nums[i]) % 2 === 0) { // same parity
        prevGood = i
        ans[i] = i
    } else {
        ans[i] = prevGood
    }
}
return queries.map(q => ans[q[1]] <= q[0])
};