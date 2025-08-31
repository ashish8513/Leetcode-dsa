
// Code


// Testcase
// Test Result
// Test Result
// 37. Sudoku Solver
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.


/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
    const m = board.length
    const n = board[0].length

    const backtraking = (i, j)=>{
        // BASE CASE: sodoku has solution and it is solved
        if(i === m && j === 0) return true

        // next index (new i j)
        let x = i
        let y = j+1
        if(y >= n){
            x = i+1
            y = 0
        }

        // if cur value is number continue checking with backtraking
        if(board[i][j] !== '.'){

            return backtraking(x, y)

        } else {
            
            // if cur value is '.' -> try all possibile number from 1 to 9
            for(let num = 1; num <= 9; num++){
                let candidate = String(num)
                // isGood -> check if candidate can satisfy the rules
                if(isGood(board, i, j, candidate)){
                    board[i][j] = candidate
                    // if found a solution -> stop backtraking
                    if(backtraking(x, y)) return true
                    board[i][j] = '.'
                }
            }

        }

        return false
    }


    // Main function starter
    backtraking(0, 0)
};

// check if candidate can satisfy rules
function isGood(board, x, y, candidate){
    /* ROW and COL */
    for(let i = 0; i < board.length; i++){
        if(board[i][y] === candidate || board[x][i] === candidate){
            return false 
        }
    }

    /* BOX */
    let startX = Math.floor(x / 3) * 3
    let startY = Math.floor(y / 3) * 3
    for(let i = startX; i < startX+3; i++){
        for(let j = startY; j < startY+3; j++){
            if(board[i][j] === candidate){
                return false
            }
        }
    }


    return true
}