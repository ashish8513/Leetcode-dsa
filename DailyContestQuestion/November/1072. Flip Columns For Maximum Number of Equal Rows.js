// You are given an m x n binary matrix matrix.

// You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).

// Return the maximum number of rows that have all values equal after some number of flips.

/**
 * @param {number[][]} matrix
 * @return {number}
 */
var maxEqualRowsAfterFlips = function(matrix) {
    const ROWS = matrix.length, COLS = matrix[0].length;
    if (COLS === 1) return ROWS;
    const flipCount = new Map();

    for (let row = 0; row < ROWS; row++) {
        let command1 = '';
        let command2 = '';
        for (let col = 0; col < COLS; col++) {
            if (!matrix[row][col]) {
                command1 += 'f';
                command2 += 'n';
            } else {
                command1 += 'n';
                command2 += 'f';
            }
        }
        if (!flipCount.has(command1)) {
            flipCount.set(command1, 0);
        }
        flipCount.set(command1, flipCount.get(command1) + 1);
        
        if (!flipCount.has(command2)) {
            flipCount.set(command2, 0);
        }
        flipCount.set(command2, flipCount.get(command2) + 1);
    }

    let max = [null, 0];
    for (const [command, count] of flipCount.entries()) {
        if (count > max[1]) {
            max[0] = command;
            max[1] = count;
        }
    }
 
    let noOp1 = flipCount.get("f".repeat(COLS + 1)) || 0;
    let noOp2 = flipCount.get("n".repeat(COLS + 1)) || 0;

    if (noOp1 + noOp2 > max[1]) {
        max[1] = 0;
    }
    return max[1];
};