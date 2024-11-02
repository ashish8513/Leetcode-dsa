// You may recall that an array arr is a mountain array if and only if:

// arr.length >= 3
// There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.


/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumMountainRemovals = function(nums) {
    let n = nums.length;
    let lis = new Array(n).fill(0);
    let lds = new Array(n).fill(0);

    for (let i=0; i<n; i++) {
        let temp = 0;
        for (let x=0; x<=i; x++) {
            if (nums[x] < nums[i]) {
                temp = Math.max(temp, lis[x]);
            }
        }
        lis[i] = temp+1;
    }
    for (let i=n-1; i>=0; i--) {
        let temp = 0;
        for (let x=n-1; x>=i; x--) {
            if (nums[x] < nums[i]) {
                temp = Math.max(temp, lds[x]);
            }
        }
        lds[i] = temp+1;
    }
    let maxLen = 0;
    for (let i=1; i<n-1; i++) {
        if (lds[i] != 1 && lis[i] != 1) {
            maxLen = Math.max(maxLen, lis[i] + lds[i]-1);
        }
    }
    
    return n-maxLen;

};