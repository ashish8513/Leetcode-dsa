// You are given a m x n matrix grid consisting of non-negative integers where grid[row][col] represents the minimum time required to be able to visit the cell (row, col), which means you can visit the cell (row, col) only when the time you visit it is greater than or equal to grid[row][col].

// You are standing in the top-left cell of the matrix in the 0th second, and you must move to any adjacent cell in the four directions: up, down, left, and right. Each move you make takes 1 second.

// Return the minimum time required in which you can visit the bottom-right cell of the matrix. If you cannot visit the bottom-right cell, then return -1.

 
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumTime = function(grid) {
    if(grid[0][1] > 1 && grid[1][0] > 1) return -1

    const m = grid.length
    const n = grid[0].length
    const dirs = [[0,1],[1,0],[0,-1],[-1,0]]
    const visited = Array.from({length: m}, ()=>Array(n).fill(false))
    visited[0][0] = true

    const pq = new MinPriorityQueue({priority: x => x[0]})
    pq.enqueue([0,0,0])

    while(!pq.isEmpty()){
        let [t,i,j] = pq.dequeue().element

        for(let [dx, dy] of dirs){
            let x = i+dx
            let y = j+dy
            if(x < 0 || x >= m) continue
            if(y < 0 || y >= n) continue
            if(visited[x][y] === true) continue

            let newTime = t+1
            if(grid[x][y] > newTime){
                newTime += Math.floor((grid[x][y] - t) / 2) * 2
            }

            if(x === m-1 && y === n-1){
                return newTime
            }
            
            visited[x][y] = true
            pq.enqueue([newTime, x, y])
        }
    }


    return -1
};