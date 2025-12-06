// You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.

// Return the total number of ways to partition nums under this condition.

// Since the answer may be too large, return it modulo 109 + 7.



var countPartitions = function(nums, k) {
    const n = nums.length;
    const MOD = 1_000_000_007;

    const dp = new Array(n + 1).fill(0);
    const prefix = new Array(n + 1).fill(0);

    dp[0] = 1;
    prefix[0] = 1;

    let minQ = [];  // store indices, not values
    let maxQ = [];
    let left = 0;

    for (let right = 0; right < n; right++) {

        // maintain min deque (increasing)
        while (minQ.length && nums[minQ[minQ.length - 1]] > nums[right]) {
            minQ.pop();
        }
        minQ.push(right);

        // maintain max deque (decreasing)
        while (maxQ.length && nums[maxQ[maxQ.length - 1]] < nums[right]) {
            maxQ.pop();
        }
        maxQ.push(right);

        // shrink window if invalid
        while (nums[maxQ[0]] - nums[minQ[0]] > k) {
            left++;
            if (minQ[0] < left) minQ.shift();
            if (maxQ[0] < left) maxQ.shift();
        }

        // dp sum range: dp[left] ... dp[right]
        const total = (prefix[right] - (left > 0 ? prefix[left - 1] : 0) + MOD) % MOD;
        dp[right + 1] = total;
        prefix[right + 1] = (prefix[right] + dp[right + 1]) % MOD;
    }

    return dp[n];
};
