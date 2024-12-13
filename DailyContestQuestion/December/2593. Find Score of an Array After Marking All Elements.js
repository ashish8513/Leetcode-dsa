// You are given an array nums consisting of positive integers.

// Starting with score = 0, apply the following algorithm:

// Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
// Add the value of the chosen integer to score.
// Mark the chosen element and its two adjacent elements if they exist.
// Repeat until all the array elements are marked.
// Return the score you get after applying the above algorithm.
/**
 * @param {number[]} nums
 * @return {number}
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var findScore = function(nums) {
    const n = nums.length;
    const marked = Array(n).fill(false); // Array to track marked elements
    let score = 0;
  
    // Step 1: Create an array of [value, index] pairs
    const elements = nums.map((value, index) => [value, index]);
  
    // Step 2: Sort by value, then by index
    elements.sort((a, b) => a[0] - b[0] || a[1] - b[1]);
  
    // Step 3: Process each element
    for (const [value, index] of elements) {
      if (marked[index]) continue; // Skip if already marked
  
      // Add value to the score
      score += value;
  
      // Mark the element and its neighbors
      marked[index] = true;
      if (index > 0) marked[index - 1] = true;
      if (index < n - 1) marked[index + 1] = true;
    }
  
    return score;
  };