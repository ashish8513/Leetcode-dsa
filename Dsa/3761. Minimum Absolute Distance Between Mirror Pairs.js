// You are given an integer array nums.

// A mirror pair is a pair of indices (i, j) such that:

// 0 <= i < j < nums.length, and
// reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. Leading zeros are omitted after reversing, for example reverse(120) = 21.
// Return the minimum absolute distance between the indices of any mirror pair. The absolute distance between indices i and j is abs(i - j).

// If no mirror pair exists, return -1.

/**
 * @param {number[]} nums
 * @return {number}
 */
function minMirrorPairDistance(nums) {
    let ans = Infinity;
    const seen = new Map();

    for (let i = 0; i < nums.length; i++) {
        const n = nums[i];

        if (seen.has(n)) {
            ans = Math.min(ans, i - seen.get(n));
        }

        
        let x = n;
        let reversed = 0;

        while (x > 0) {
            reversed = reversed * 10 + (x % 10);
            x = Math.floor(x / 10);
        }

        seen.set(reversed, i);
    }

    return ans === Infinity ? -1 : ans;
}
