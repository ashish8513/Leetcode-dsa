// Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

// Return the length of the shortest subarray to remove.

// A subarray is a contiguous subsequence of the array.

 

/**
 * @param {number[]} arr
 * @return {number}
 */
var findLengthOfShortestSubarray = function(arr) {
    let n = arr.length;
    let s = 0;
    let e = n - 1;
    
    while (s + 1 < n && arr[s] <= arr[s + 1]) {
        s++;
    }
    while (e - 1 >= 0 && arr[e] >= arr[e - 1]) {
        e--;
    }
    
    if (s >= e) return 0;
    
    let max = Math.max(s + 1, n - e);
    
    for (let i = 0; i <= s; i++) {
        for (let j = e; j < n; j++) {
            if (arr[j] >= arr[i]) {
                max = Math.max(i + 1 + n - j, max);
                break;
            }
        }
    }
    
    return n - max;
};