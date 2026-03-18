// You are given a 0-indexed integer matrix grid and an integer k.

// Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.

 class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (i && j) grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
                else if (i) grid[i][j]+=grid[i-1][j];
                else if (j) grid[i][j]+=grid[i][j-1];

                if (grid[i][j]<=k) cnt++;
            }
        }
        return cnt;
    }
};
