// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 /**
 * @param {number[][]} heightMap
 * @return {number}
 */
var trapRainWater = function (heightMap) {
    const m = heightMap.length;
    const n = heightMap[0].length;

    if (m < 3 || n < 3) return 0; // No water can be trapped if the grid is too small

    const visited = Array.from({ length: m }, () => Array(n).fill(false));
    const minHeap = [];

    // Helper function to add cells to the heap
    const addToHeap = (x, y, height) => {
        minHeap.push([height, x, y]);
        minHeap.sort((a, b) => a[0] - b[0]); // Maintain heap property
        visited[x][y] = true;
    };

    // Add all boundary cells to the heap
    for (let i = 0; i < m; i++) {
        addToHeap(i, 0, heightMap[i][0]);
        addToHeap(i, n - 1, heightMap[i][n - 1]);
    }
    for (let j = 1; j < n - 1; j++) {
        addToHeap(0, j, heightMap[0][j]);
        addToHeap(m - 1, j, heightMap[m - 1][j]);
    }

    let waterTrapped = 0;
    const directions = [[0, 1], [0, -1], [1, 0], [-1, 0]];

    // Process the cells in the heap
    while (minHeap.length > 0) {
        const [height, x, y] = minHeap.shift();

        for (const [dx, dy] of directions) {
            const nx = x + dx;
            const ny = y + dy;

            // Process only unvisited cells inside the grid
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                // Calculate water trapped at this neighbor
                waterTrapped += Math.max(0, height - heightMap[nx][ny]);

                // Update the neighbor's height and add it to the heap
                addToHeap(nx, ny, Math.max(height, heightMap[nx][ny]));
            }
        }
    }

    return waterTrapped;
};