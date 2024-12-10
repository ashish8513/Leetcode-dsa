// Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

// A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var luckyNumbers  = function(matrix) {
    for(let i=0;i<matrix.length;i++){
        let arrayelem=matrix[i]
        let minrow=Math.min(...arrayelem)
         let index=arrayelem.indexOf(minrow)
         if(matrix.every(elem=> elem[index]<=minrow)) return [minrow] 
    }
    return []
 
 };