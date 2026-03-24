// Given a 0-indexed 2D integer matrix grid of size n * m, we define a 0-indexed 2D matrix p of size n * m as the product matrix of grid if the following condition is met:

// Each element p[i][j] is calculated as the product of all elements in grid except for the element grid[i][j]. This product is then taken modulo 12345.
// Return the product matrix of grid.

 
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;

        int size = n * m;
        vector<int> res(size);

        long long prefix = 1;

        //prefix pass
        int idx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[idx] = prefix;
                prefix = (prefix * grid[i][j]) % mod;
                idx++;
            }
        }

        // suffix pass
        long long suffix = 1;
        for(int i = size - 1; i >= 0; i--) {
            res[i] = (res[i] * suffix) % mod;

            int r = i / m;
            int c = i % m;
            suffix = (suffix * grid[r][c]) % mod;
        }

        // converting back to 2D
        vector<vector<int>> result(n, vector<int>(m));
        idx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                result[i][j] = res[idx++];
            }
        }

        return result;
    }
};
