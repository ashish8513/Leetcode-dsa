// You are given an m x n integer matrix grid, and three integers x, y, and k.

// The integers x and y represent the row and column indices of the top-left corner of a square submatrix and the integer k represents the size (side length) of the square submatrix.

// Your task is to flip the submatrix by reversing the order of its rows vertically.

// Return the updated matrix.

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = 0; i < k / 2; i++) {
            for(int j = y; j < y + k; j++) {
                swap(grid[x + i][j], grid[x + k - 1 - i][j]);
            }
        }
        return grid;
    }
};
