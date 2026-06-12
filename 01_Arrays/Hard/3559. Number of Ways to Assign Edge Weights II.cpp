// There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.

// Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.

// The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.

// You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways to assign weights to edges in the path such that the cost of the path between ui and vi is odd.

// Return an array answer, where answer[i] is the number of valid assignments for queries[i].

// Since the answer may be large, apply modulo 109 + 7 to each answer[i].

// Note: For each query, disregard all edges not in the path between node ui and vi.

class Solution {
public:
    static const int MOD = 1e9 + 7;
    int LOG;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<int>> adj;

    void dfs(int node, int parent) {
        up[node][0] = parent;

        for (int i = 1; i < LOG; i++) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }

        for (int nxt : adj[node]) {
            if (nxt == parent) continue;
            depth[nxt] = depth[node] + 1;
            dfs(nxt, node);
        }
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];

        for (int i = LOG - 1; i >= 0; i--) {
            if (diff & (1 << i)) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        adj.assign(n + 1, {});
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, 1));

        dfs(1, 1);

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            int L = lca(u, v);

            int dist = depth[u] + depth[v] - 2 * depth[L];

            if (dist == 0) {
                ans.push_back(0);
            } else {
                ans.push_back((int)modPow(2, dist - 1));
            }
        }

        return ans;
    }
};