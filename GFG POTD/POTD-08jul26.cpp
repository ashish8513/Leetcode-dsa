//? Largest Unblocked Submatrix

// Given two integers n and m, and an array arr[][] of size k, where arr[i] = [r, c] represents a blocked cell (1-based indexing) in an n × m grid. Each blocked cell blocks its entire row and column. Find the largest continuous unblocked area in the grid.

// Note: No two blocked cells are in the same row or the same column.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        vector<int> rows, cols;

        for (auto &x : arr) {
            rows.push_back(x[0]);
            cols.push_back(x[1]);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int maxRows = 0, prev = 0;

        for (int r : rows) {
            maxRows = max(maxRows, r - prev - 1);
            prev = r;
        }
        maxRows = max(maxRows, n - prev);

        int maxCols = 0;
        prev = 0;

        for (int c : cols) {
            maxCols = max(maxCols, c - prev - 1);
            prev = c;
        }
        maxCols = max(maxCols, m - prev);

        return maxRows * maxCols;
    }
};