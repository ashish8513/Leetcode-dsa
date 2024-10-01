// Given an array of integers arr of even length n and an integer k.

// We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

// Return true If you can find a way to do that or false otherwise.
function canArrange(arr, k) {
    const remainderCount = new Array(k).fill(0);

    for (const num of arr) {
        const remainder = ((num % k) + k) % k; // Ensure non-negative remainder
        remainderCount[remainder]++;
    }

    // Check for pairs
    for (let i = 1; i < k; i++) {
        if (remainderCount[i] !== remainderCount[k - i]) {
            return false; // If counts don't match, cannot form pairs
        }
    }

    // Check the case for remainder 0
    if (remainderCount[0] % 2 !== 0) {
        return false; // There should be an even count of remainder 0
    }

    return true; // All conditions are satisfied
}

// Example usage:
const arr = [9, 7, 5, 3];
const k = 6;
console.log(canArrange(arr, k)); // Output: true or false
