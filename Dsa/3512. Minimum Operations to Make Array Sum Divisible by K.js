// You are given an integer array nums and an integer k. You can perform the following operation any number of times:

// Select an index i and replace nums[i] with nums[i] - 1.
// Return the minimum number of operations required to make the sum of the array divisible by k.  


var minOperations = function(nums, k) {
    let sum = nums.reduce((a, b) => a + b, 0);
    let remainder = sum % k;
    if (remainder === 0) return 0;
    return remainder;
};
