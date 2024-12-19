// You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

// We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

// Return the largest number of chunks we can make to sort the array.

/**
 * @param {number[]} arr
 * @return {number}
 */
var maxChunksToSorted = function(arr) {
    if(arr == null || arr.length === 0)
   return 0;

   let count = 0;
   let max = 0;
   for(let i=0;i<arr.length; i++){
       max=Math.max(max, arr[i]);
       if(max === i)
       count++;
       
   }
   return count;
};