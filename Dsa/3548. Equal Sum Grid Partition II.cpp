// You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

// Each of the two resulting sections formed by the cut is non-empty.
// The sum of elements in both sections is equal, or can be made equal by discounting at most one single cell in total (from either section).
// If a cell is discounted, the rest of the section must remain connected.
// Return true if such a partition exists; otherwise, return false.

// Note: A section is connected if every cell in it can be reached from any other cell by moving up, down, left, or right through other cells in the section.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool canRemove(int r1, int c1, int r2, int c2, int i, int j) {
        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;

        if (rows == 1) return (j == c1 || j == c2);
        if (cols == 1) return (i == r1 || i == r2);

        return true;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> prefRow(n, 0), prefCol(m, 0);
        map<long long, vector<pair<int,int>>> mp;

        // build prefix + map
        for (int i = 0; i < n; i++) {
            long long val = 0;
            for (int j = 0; j < m; j++) {
                val += grid[i][j];
                mp[grid[i][j]].push_back({i, j});
            }
            prefRow[i] = val + (i ? prefRow[i - 1] : 0);
        }

        for (int j = 0; j < m; j++) {
            long long val = 0;
            for (int i = 0; i < n; i++) {
                val += grid[i][j];
            }
            prefCol[j] = val + (j ? prefCol[j - 1] : 0);
        }

        long long total = prefRow[n - 1];

        // horizontal cuts
        for (int i = 0; i < n - 1; i++) {
            long long top = prefRow[i];
            long long bottom = total - top;

            if (top == bottom) return true;

            long long diff = abs(top - bottom);
            if (!mp.count(diff)) continue;

            if (top > bottom) {
                for (auto &p : mp[diff]) {
                    int x = p.first, y = p.second;
                    if (x <= i && canRemove(0, 0, i, m - 1, x, y))
                        return true;
                }
            } else {
                for (auto &p : mp[diff]) {
                    int x = p.first, y = p.second;
                    if (x > i && canRemove(i + 1, 0, n - 1, m - 1, x, y))
                        return true;
                }
            }
        }

        // vertical cuts
        for (int j = 0; j < m - 1; j++) {
            long long left = prefCol[j];
            long long right = total - left;

            if (left == right) return true;

            long long diff = abs(left - right);
            if (!mp.count(diff)) continue;

            if (left > right) {
                for (auto &p : mp[diff]) {
                    int x = p.first, y = p.second;
                    if (y <= j && canRemove(0, 0, n - 1, j, x, y))
                        return true;
                }
            } else {
                for (auto &p : mp[diff]) {
                    int x = p.first, y = p.second;
                    if (y > j && canRemove(0, j + 1, n - 1, m - 1, x, y))
                        return true;
                }
            }
        }

        return false;
    }
};
