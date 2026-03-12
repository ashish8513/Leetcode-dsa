// You are given an integer n, representing n nodes numbered from 0 to n - 1 and a list of edges, where edges[i] = [ui, vi, si, musti]:

// ui and vi indicates an undirected edge between nodes ui and vi.
// si is the strength of the edge.
// musti is an integer (0 or 1). If musti == 1, the edge must be included in the spanning tree. These edges cannot be upgraded.
// You are also given an integer k, the maximum number of upgrades you can perform. Each upgrade doubles the strength of an edge, and each eligible edge (with musti == 0) can be upgraded at most once.

// The stability of a spanning tree is defined as the minimum strength score among all edges included in it.

// Return the maximum possible stability of any valid spanning tree. If it is impossible to connect all nodes, return -1.

// Note: A spanning tree of a graph with n nodes is a subset of the edges that connects all nodes together (i.e. the graph is connected) without forming any cycles, and uses exactly n - 1 edges


struct DSU {
    vector<int> p, sz;
    int c;
    DSU(int n) {
        p.resize(n);
        sz.resize(n, 1);
        iota(p.begin(), p.end(), 0);
        c = n;
    }
    int f(int i) {
        if (p[i] == i) return i;
        return p[i] = f(p[i]);
    }
    bool u(int i, int j) {
        int x = f(i);
        int y = f(j);
        if (x != y) {
            if (sz[x] < sz[y]) swap(x, y);
            p[y] = x;
            sz[x] += sz[y];
            c--;
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU g(n);
        for (auto &e : edges) g.u(e[0], e[1]);
        if (g.c > 1) return -1;
        DSU b(n);
        int m = 2e9; 
        vector<pair<int, pair<int, int>>> o;
        for (auto &e : edges) {
            if (e[3] == 1) {
                m = min(m, e[2]);
                if (!b.u(e[0], e[1])) return -1;
            } else o.push_back({e[2], {e[0], e[1]}});
            
        }
        auto isOk = [&](int t, DSU d) {
            for (auto &e : o) {
                if (e.first >= t) {
                    d.u(e.second.first, e.second.second);
                }
            }
            int u = 0;
            for (auto &e : o) {
                if (e.first < t && 2 * e.first >= t) {
                    if (d.u(e.second.first, e.second.second)) {
                        u++;
                    }
                }
            }
            return d.c == 1 && u <= k;
        };
        int l = -1;
        int h = min(200000, m) + 1; 
        while (h - l > 1) {
            int mid = l + (h - l) / 2;
            if (isOk(mid, b)) l = mid;
            else h = mid;
        }
        return l;
    }
};
