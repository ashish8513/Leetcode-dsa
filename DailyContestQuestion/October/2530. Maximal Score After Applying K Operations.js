// You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.

// In one operation:

// choose an index i such that 0 <= i < nums.length,
// increase your score by nums[i], and
// replace nums[i] with ceil(nums[i] / 3).
// Return the maximum possible score you can attain after applying exactly k operations.

// The ceiling function ceil(val) is the least integer greater than or equal to val.


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
function maxKelements(nums, k) {
    const pq = new MaxPriorityQueue(); // Assume MaxPriorityQueue is available
    nums.forEach(num => pq.enqueue(num));
    let ans = 0;
    while (k > 0) {
        const v = pq.dequeue().element;
        ans += v;
        pq.enqueue(Math.floor((v + 2) / 3));
        k--;
    }
    return ans;
}
