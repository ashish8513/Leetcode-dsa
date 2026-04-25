// You are given an integer side, representing the edge length of a square with corners at (0, 0), (0, side), (side, 0), and (side, side) on a Cartesian plane.

// You are also given a positive integer k and a 2D integer array points, where points[i] = [xi, yi] represents the coordinate of a point lying on the boundary of the square.

// You need to select k elements among points such that the minimum Manhattan distance between any two points is maximized.

// Return the maximum possible minimum Manhattan distance between the selected k points.

// The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> pos(n);
        
        // Map each boundary point to a perimeter position [0, 4*side)
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            if (y == 0)            pos[i] = x;
            else if (x == side)    pos[i] = side + y;
            else if (y == side)    pos[i] = 2LL * side + (side - x);
            else                   pos[i] = 3LL * side + (side - y);
        }
        sort(pos.begin(), pos.end());
        
        long long P = 4LL * side;
        
        // Duplicate the array to handle circular wrap-around
        vector<long long> ext(2 * n);
        for (int i = 0; i < n; i++) {
            ext[i]     = pos[i];
            ext[i + n] = pos[i] + P;
        }
        
        // Can we select k points with pairwise perimeter gap >= d ?
        auto check = [&](long long d) {
            for (int i = 0; i < n; i++) {
                long long cur = ext[i];
                int idx = i;
                bool ok = true;
                
                for (int j = 1; j < k; j++) {
                    long long target = cur + d;
                    auto it = lower_bound(
                        ext.begin() + idx + 1,
                        ext.begin() + i + n,
                        target
                    );
                    if (it == ext.begin() + i + n) { ok = false; break; }
                    idx = it - ext.begin();
                    cur = *it;
                }
                
                // Wrap-around check: gap from last back to start must be >= d
                if (ok && (ext[i] + P - cur) >= d) return true;
            }
            return false;
        };
        
        // Binary search on the answer
        long long lo = 1, hi = 2LL * side, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (check(mid)) { ans = mid; lo = mid + 1; }
            else            { hi = mid - 1; }
        }
        return (int) ans;
    }
};
