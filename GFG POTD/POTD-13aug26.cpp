//? Longest Path in a Directed Acyclic Graph
// Given a weighted Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1, represented by edges[][], where edges[i] = [u, v, w] denotes a directed edge from u to v with weight w, and a source vertex src.

// Return the distance array, where the value at index i represents the longest distance from s to vertex i.
// If a vertex is unreachable from s, store INT_MIN for that vertex. The driver code will automatically display INT_MIN as INF.

class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        
        // 1. Adjacency list
        vector<vector<pair<int, int>>> adj(V);
        vector<int> indegree(V, 0);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            indegree[v]++;
        }

        // 2. Topological Sort
        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto &[v, w] : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // 3. Distance initialization
        vector<int> dist(V, INT_MIN);
        dist[src] = 0;

        // 4. Longest distance using DP
        for (int u : topo) {

            // Unreachable node
            if (dist[u] == INT_MIN)
                continue;

            for (auto &[v, w] : adj[u]) {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }

        return dist;
    }
};