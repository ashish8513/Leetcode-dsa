// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.

/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {
    if(nums.length == 1) return 0;
    let n = nums.length;
    let lo = 0, hi = n-1;
    while(lo <= hi) {
        let mid = lo + Math.floor((hi - lo) / 2);
        if(mid+1 >= n && nums[mid] > nums[mid - 1]) {
            // rightmost element
            return mid;
        }
        if(mid - 1 < 0 && nums[mid] > nums[mid+1]) {
            return mid;
        }
        if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
            return mid;
        }
        if(nums[mid] < nums[mid+1]) { // inc curve
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
};