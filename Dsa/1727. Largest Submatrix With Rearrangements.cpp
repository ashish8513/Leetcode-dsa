// You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

// Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally


class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==1)
                {
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        for(int i=m-1;i>=0;i--)
        {
            sort(matrix[i].begin(),matrix[i].end());
            int f=1;
            for(int j=n-1;j>=0;j--)
            {
                ans=max(ans,matrix[i][j]*f);
                f++;
            }
        }
        return ans;

    }
};
