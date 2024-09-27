// You are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using all the elements from original.

// The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.

// Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.

/**
 * @param {number[]} original
 * @param {number} m
 * @param {number} n
 * @return {number[][]}
 */
function construct2DArray(original, m, n) {
    if (original.length !== m * n) {
        return [];
    }
    
    const result = [];
    
    for (let i = 0; i < m; i++) {
        result.push(original.slice(i * n, i * n + n));
    }
    
    return result;
}

const original = [1, 2, 3, 4, 5, 6];
const m = 2, n = 3;
console.log(construct2DArray(original, m, n));