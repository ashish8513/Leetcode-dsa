// You are given an array of integers nums of length n and a positive integer k.

// The power of an array is defined as:

// Its maximum element if all of its elements are consecutive and sorted in ascending order.
// -1 otherwise.
// You need to find the power of all 
// subarrays
//  of nums of size k.

// Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var resultsArray = function(nums, k) {
    let n = nums.length;
 let increasingOrderSubarraySize = 1;
 let result = [];

 for(let i = 0; i < n; i++){

     if(i > 0 && nums[i] === nums[i - 1] + 1){
         increasingOrderSubarraySize += 1;
     }
     else{
         increasingOrderSubarraySize = 1;
     }

     if(i >= k - 1){
         if(increasingOrderSubarraySize >= k){
             result.push(nums[i]);
         }
         else{
             result.push(-1);
         }
     }
 }

 return result;
};