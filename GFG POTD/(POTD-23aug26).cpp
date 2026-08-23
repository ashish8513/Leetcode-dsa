// Geek in a Maze

// Given a maze mat[][] of size n × m, where each cell is either:

// '.' representing an empty cell, or
// '#' representing an obstacle.
// Find the number of distinct empty cells that Geek can visit starting from the cell (r, c).

// Geek can move up, down, left, or right to an adjacent non-obstacle cell inside the maze.
// On any path, Geek can make at most u upward moves and d downward moves.
// There is no limit on the number of left or right moves.
// If the starting cell is an obstacle, return 0.
// Note :  There can be multiple paths starting from [r, c].

class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {

        int n = mat.size();
        int m = mat[0].size();

        if (mat[r][c] == '#')
            return 0;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        deque<pair<int, int>> q;

        dist[r][c] = 0;
        q.push_front({r, c});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop_front();

            for (int k = 0; k < 4; k++) {
                int nx = x + dr[k];
                int ny = y + dc[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if (mat[nx][ny] == '#')
                    continue;

                int cost = (nx < x) ? 1 : 0;

                if (dist[nx][ny] > dist[x][y] + cost) {
                    dist[nx][ny] = dist[x][y] + cost;

                    if (cost == 0)
                        q.push_front({nx, ny});
                    else
                        q.push_back({nx, ny});
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (dist[i][j] == INT_MAX)
                    continue;

                int upMoves = dist[i][j];

                int downMoves = upMoves + i - r;

                if (upMoves <= u && downMoves <= d)
                    ans++;
            }
        }

        return ans;
    }
};
