//? 3286. Find a Safe Walk Through a Grid

// You are given an m x n binary matrix grid and an integer health.

// You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).

// You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.

// Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.

// Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

static constexpr int dirs[5] = {0, 1, 0, -1, 0};
static constexpr int INF = 1e9;
static int dist[4096];
class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        const int m = grid.size(), n = grid[0].size();
        fill(dist, dist + 4096, INF);
        deque<int> dq;
        dq.push_back(0);
        dist[0] = grid[0][0];
        while (!dq.empty())
        {
            const int pos = dq.front();
            dq.pop_front();
            if (dist[pos] == health)
                break;
            const int x = pos >> 6, y = pos & 63;
            if (x == m - 1 && y == n - 1)
                break;
            for (int d = 0; d < 4; ++d)
            {
                const int nx = x + dirs[d], ny = y + dirs[d + 1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n)
                {
                    const int w = grid[nx][ny], npos = (nx << 6) | ny;
                    if (dist[pos] + w < dist[npos])
                    {
                        dist[npos] = dist[pos] + w;
                        if (w)
                            dq.push_back(npos);
                        else
                            dq.push_front(npos);
                    }
                }
            }
        }
        return dist[((m - 1) << 6) | (n - 1)] < health;
    }
};