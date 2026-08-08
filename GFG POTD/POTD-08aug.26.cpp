//? Min Edge Movements to Connect a Graph

// Given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation.

// Find the minimum number of operations required to connect the graph. If it is not possible to connect the graph, return -1.

class Solution {
public:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node], parent);
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(u, parent);
        v = findParent(v, parent);

        if (u == v)
            return;

        if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if (rank[u] > rank[v]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    int minEdgesReq(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        // Minimum n-1 edges are required
        if (m < n - 1)
            return -1;

        vector<int> parent(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Connect components using existing edges
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            unionSet(u, v, parent, rank);
        }

        // Count connected components
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (findParent(i, parent) == i)
                components++;
        }

        // Need components - 1 edge movements
        return components - 1;
    }
};  