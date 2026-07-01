//? 2812. Find the Safest Path in a Grid
// You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

// A cell containing a thief if grid[r][c] = 1
// An empty cell if grid[r][c] = 0
// You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

// The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.

// Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

// An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

// The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.
#include <iostream>
#include <Vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> safety(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> bfs;

        // Collect all thief positions
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    safety[r][c] = 0;
                    bfs.push({r, c});
                }
            }
        }

        // Directions for movement
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        // Multi-source BFS to compute distance from nearest thief
        while (!bfs.empty()) {
            auto [r, c] = bfs.front(); bfs.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && safety[nr][nc] == INT_MAX) {
                    safety[nr][nc] = safety[r][c] + 1;
                    bfs.push({nr, nc});
                }
            }
        }

        // Binary search for maximum safeness factor
        int left = 0, right = n * 2, best = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (pathExists(safety, mid)) {
                best = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return best;
    }

private:
    bool pathExists(vector<vector<int>>& safety, int limit) {
        int n = safety.size();
        if (safety[0][0] < limit) return false;

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (r == n - 1 && c == n - 1) return true;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc] && safety[nr][nc] >= limit) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }
};