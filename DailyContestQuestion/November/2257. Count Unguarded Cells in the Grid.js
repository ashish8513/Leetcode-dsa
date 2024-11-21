// You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

// A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

// Return the number of unoccupied cells that are not guarded.


/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} guards
 * @param {number[][]} walls
 * @return {number}
 */
var countUnguarded = function (m, n, guards, walls) {
    const g = Array.from({ length: m }, () => Array(n).fill(0));

    // Mark guards and walls on the grid
    for (const [i, j] of guards) {
        g[i][j] = 2;
    }
    for (const [i, j] of walls) {
        g[i][j] = 2;
    }

    const directions = [-1, 0, 1, 0, -1];

    // Mark cells guarded by guards
    for (const [i, j] of guards) {
        for (let d = 0; d < 4; d++) {
            let x = i;
            let y = j;

            while (
                x + directions[d] >= 0 &&
                x + directions[d] < m &&
                y + directions[d + 1] >= 0 &&
                y + directions[d + 1] < n &&
                g[x + directions[d]][y + directions[d + 1]] < 2
            ) {
                x += directions[d];
                y += directions[d + 1];
                g[x][y] = 1;
            }
        }
    }

    // Count unguarded cells
    let unguardedCount = 0;
    for (const row of g) {
        for (const cell of row) {
            if (cell === 0) {
                unguardedCount++;
            }
        }
    }

    return unguardedCount;
};