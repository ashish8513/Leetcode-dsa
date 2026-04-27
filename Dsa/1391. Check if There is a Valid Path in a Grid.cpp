// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:

// 1 which means a street connecting the left cell and the right cell.
// 2 which means a street connecting the upper cell and the lower cell.
// 3 which means a street connecting the left cell and the lower cell.
// 4 which means a street connecting the right cell and the lower cell.
// 5 which means a street connecting the left cell and the upper cell.
// 6 which means a street connecting the right cell and the upper cell.

// You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

// Notice that you are not allowed to change any street.

// Return true if there is a valid path in the grid or false otherwise.

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> direct({
            {{0, -1}, {0, 1}},
            {{-1, 0}, {1, 0}},
            {{0, -1}, {1, 0}},
            {{0, 1}, {1, 0}},
            {{0, -1}, {-1, 0}},
            {{0, 1}, {-1, 0}}
        });
        int m=grid.size();
        int n=grid[0].size();
        queue<vector<int>>Q;
        Q.push({0,0});
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        visited[0][0]=true;
        while(!Q.empty()){
            vector<int>curr=Q.front();
            Q.pop();
            int row=curr[0];
            int col=curr[1];
            for(auto &d:direct[grid[row][col]-1]){
                int nr=row+d[0];
                int nc=col+d[1];
                if(nr<0 || nr>=m || nc<0 || nc>=n || visited[nr][nc]){
                    continue;
                }
                for(auto &dir:direct[grid[nr][nc]-1]){
                    if(nr+dir[0]==row && nc+dir[1]==col){
                        visited[nr][nc]=true;
                        Q.push({nr,nc});
                    }
                }
            }
        }
        return visited[m-1][n-1];
    }
};
