// Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

// Example 1:

// Input: n = 13, k = 2
// Output: 10
// Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.

/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findKthNumber = function(n, k) {
    const countSteps = (prefix, n) => {
    let current = prefix;
    let next = prefix + 1;
    let steps = 0;
    
    while (current <= n) {
        steps += Math.min(n + 1, next) - current;
        current *= 10;
        next *= 10;
    }
    
    return steps;
};

let current = 1;
k--;

while (k > 0) {
    let steps = countSteps(current, n);
    
    if (steps <= k) {
        current++;
        k -= steps;
    } else {
        current *= 10;
        k--;
    }
}

return current;
};