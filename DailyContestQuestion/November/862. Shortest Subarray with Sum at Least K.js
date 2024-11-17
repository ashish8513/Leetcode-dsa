// Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

// A subarray is a contiguous part of an array.
/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var shortestSubarray = function(A, K) {
    let N = A.length, res = N + 1;
       let d = [];
       for (let i = 0; i < N; i++) {
           if (i > 0)
               A[i] += A[i - 1];
           if (A[i] >= K)
               res = Math.min(res, i + 1);
           while (d.length > 0 && A[i] - A[d[0]] >= K){
               res = Math.min(res, (i - d[0]))
               d.shift()
           }
           while (d.length > 0 && A[i] <= A[d[d.length-1]])
               d.pop();
           d.push(i);
       }
       return res <= N ? res : -1;
};