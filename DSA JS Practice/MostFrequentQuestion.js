
/**
 * @param {number[]} nums
 * @return {number}
 */
function mostFrequentEven(nums) {
    // Create a map to store frequencies of even numbers
    const freqMap = new Map();

    // Count frequencies of even numbers
    nums.forEach(num => {
        if (num % 2 === 0) { // Check if the number is even
            freqMap.set(num, (freqMap.get(num) || 0) + 1);
        }
    });

    // If there are no even numbers, return -1
    if (freqMap.size === 0) {
        return -1;
    }

    let mostFrequent = -1;
    let maxFrequency = 0;

    // Iterate over the frequency map to find the most frequent even number
    freqMap.forEach((frequency, num) => {
        // Check if current number has higher frequency or, in case of a tie, is smaller
        if (frequency > maxFrequency || (frequency === maxFrequency && num < mostFrequent)) {
            mostFrequent = num;
            maxFrequency = frequency;
        }
    });

    return mostFrequent;
}