// You are given an integer array nums. A subsequence of nums is called a square streak if:

// The length of the subsequence is at least 2, and
// after sorting the subsequence, each element (except the first element) is the square of the previous number.
// Return the length of the longest square streak in nums, or return -1 if there is no square streak.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

/**
 * @param {number[]} nums
 * @return {number}
 */
var longestSquareStreak = function(nums) {
    const squares = new Set();
  for (let i = 2; i < 317; ++i) {
      squares.add(i * i);
  } 

  nums = nums.filter(o => o < 317 || squares.has(o));
  nums.sort((a, b) => a - b);
  const set = new Set(nums);
  let result = -1;
  let count = 0, current;

  for (const num of nums) {
      current = num;
      count = 1;

      while (set.has(current * current)) {
          current *= current;
          ++count;
      }

      if (count > result) result = count;
  }

  return result === 1 ? -1 : result;
};