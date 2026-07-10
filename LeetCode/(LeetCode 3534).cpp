//? 3534. Path Existence Queries in a Graph II

// You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.

// You are also given an integer array nums of length n and an integer maxDiff.

// An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).

// You are also given a 2D integer array queries. For each queries[i] = [ui, vi], find the minimum distance between nodes ui and vi. If no path exists between the two nodes, return -1 for that query.

// Return an array answer, where answer[i] is the result of the ith query.

// Note: The edges between the nodes are unweighted.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> pos(n), comp(n);

        int id = 0;
        pos[arr[0].second] = 0;
        comp[0] = 0;

        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i - 1].first > maxDiff)
                id++;
            comp[i] = id;
            pos[arr[i].second] = i;
        }

        vector<int> reach(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            r = max(r, i);
            while (r + 1 < n &&
                   comp[r + 1] == comp[i] &&
                   arr[r + 1].first - arr[i].first <= maxDiff)
                r++;
            reach[i] = r;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++)
            up[0][i] = reach[i];

        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k - 1][up[k - 1][i]];

        vector<int> ans;

        for (auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            if (u > v) swap(u, v);

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int cur = u;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < v) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};