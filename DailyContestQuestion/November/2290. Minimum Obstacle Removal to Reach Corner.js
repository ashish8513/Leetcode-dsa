// You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:

// 0 represents an empty cell,
// 1 represents an obstacle that may be removed.
// You can move up, down, left, or right from and to an empty cell.

// Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).

 /**
 * @param {number[][]} grid
 * @return {number}
 */
var minimumObstacles = function(grid) {
    let dx=[[0,1],[0,-1],[1,0],[-1,0]];
    let distance=[];
    for(let i=0;i<grid.length;i++){
        distance[i]=[];
        for(let j=0;j<grid[i].length;j++){
            distance[i][j]=Number.MAX_SAFE_INTEGER;
        }
    }
    return bfs(0,0);
    
    function bfs(row,col){
        let queue=[];
        distance[row][col]=0;
        queue.push([row,col]);
        while(queue.length>0){
            let element = queue.shift();
            let row = element[0];
            let col = element[1];
            let originalDist = distance[row][col];
            for(let d=0;d<dx.length;d++){
                let i = row + dx[d][0];
                let j = col + dx[d][1];
                if(i>=0 && i<=grid.length-1 && j>=0 && j<=grid[i].length-1){
                    let dist = originalDist;
                    if(grid[i][j]===1){
                        dist++;
                    }
                    if(distance[i][j]>dist){//Update distance for this neighbour node if the new distance is smaller than the previous distance
                        queue.push([i,j]);
                        distance[i][j]=dist;
                    }
                    
                }
            }
        }
        //return the minimum distance for last cell after completing the process
        return distance[(grid.length-1)][(grid[row].length-1)];
    }
};