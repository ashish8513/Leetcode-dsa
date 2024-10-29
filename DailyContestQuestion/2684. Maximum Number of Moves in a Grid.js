// You are given a 0-indexed m x n matrix grid consisting of positive integers.

// You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

// From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
// Return the maximum number of moves that you can perform.

/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxMoves = function(grid) {
    const cache = {};
let countMoves = 0;
for (let i = 0; i < grid.length; i++) {
    countMoves = Math.max(countMoves, move(grid, i, 0, -Infinity, cache) - 1); 
}

return countMoves;
};

function move(grid, row, col, prev, cache) {
const key = row + "," + col;
if (key in cache) {
    return cache[key];
}

if (row < 0 || row >= grid.length || col >= grid[0].length || grid[row][col] <= prev) {
    return 0;
}

let count = 0;
count += Math.max(
    move(grid, row + 1, col + 1, grid[row][col], cache),
    move(grid, row - 1, col + 1, grid[row][col], cache),
    move(grid, row, col + 1, grid[row][col], cache)
);

cache[key] = count + 1;

return count + 1;
};