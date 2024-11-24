// You are given an n x n integer matrix. You can do the following operation any number of times:

// Choose any two adjacent elements of matrix and multiply each of them by -1.
// Two elements are considered adjacent if and only if they share a border.

// Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

 /**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxMatrixSum = function (matrix) {
    let res = 0, bad = 0, min = Infinity;
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            res += Math.abs(matrix[i][j]);
            if (matrix[i][j] < 0) bad++;
            min = Math.min(min, Math.abs(matrix[i][j]))
        }
    }
    if (bad % 2 === 1) res -= min * 2;
    return res;
};