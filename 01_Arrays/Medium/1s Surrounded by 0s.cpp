// Given an n × m binary matrix grid[][], find the total count of all cells containing 1 that are unable to move out of the grid through a path of adjacent 1s.

// Adjacency means you can only move in four directions: Up, Down, Left, and Right. Diagonal moves are not allowed.
// Assume that the space immediately outside the grid is an open path. Any 1 located directly on the outer boundary of the grid (first row, last row, first column, or last column) can immediately step out, and any 1 connected to it can follow and also step out of the grid.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n, m;

    bool dfs(int row, int col,
             vector<vector<int>>& grid,
             vector<vector<int>>& vis) {

        if(row == 0 || col == 0 || row == n-1 || col == m-1)
            return true;

        vis[row][col] = 1;

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {

            int nrow = row + delRow[k];
            int ncol = col + delCol[k];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               grid[nrow][ncol] == 1 &&
               !vis[nrow][ncol]) {

                if(dfs(nrow, ncol, grid, vis))
                    return true;
            }
        }

        return false;
    }

    int cntOnes(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        int cnt = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {

                    vector<vector<int>> vis(n,
                                vector<int>(m, 0));

                    if(!dfs(i, j, grid, vis)) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};