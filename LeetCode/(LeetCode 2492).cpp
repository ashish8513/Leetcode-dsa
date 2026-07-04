//? 2492. Minimum Score of a Path Between Two Cities

// You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.

// The score of a path between two cities is defined as the minimum distance of a road in this path.

// Return the minimum possible score of a path between cities 1 and n.

// Note:

// A path is a sequence of roads between two cities.
// It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
// The test cases are generated such that there is at least one path between 1 and n.
#include <iostream>
#include <vector>
using namespace std;

class UnionFind {

    vector<int> parent;
    vector<int> rank;
    vector<int> mnScore;
    int n;

public:
    UnionFind(int n) {
        this->n = (n + 1);
        parent.resize(n + 1);
        rank.resize(n + 1);
        mnScore.resize(n + 1);

        for(int i = 0; i < n +  1; i++) {
            parent[i] = i;
            rank[i] = 1;
            mnScore[i] = INT_MAX;
        }
    }

    int findParent(int node) {

        if(node == parent[node]) return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int node1, int node2, int dist) {

        int par1 = findParent(node1);
        int par2 = findParent(node2);

        if(par1 == par2) {
            mnScore[par1] = min({mnScore[par1], dist, mnScore[par2]});
            return;
        }

        if(rank[par1] < rank[par2]) {
            mnScore[par2] = min({mnScore[par2], dist, mnScore[par1]});
            parent[par1] = par2;
        }
        else if(rank[par2] < rank[par1]) {
            mnScore[par1] = min({mnScore[par1], dist, mnScore[par2]});
            parent[par2] = par1;
        }
        else {
            mnScore[par1] = min({mnScore[par1], dist, mnScore[par2]});
            parent[par2] = par1;
            rank[par1]++;
        }
    }

    int getMinScore(int node) {
        
        int parent = findParent(node);
        return mnScore[parent];
    }


};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        UnionFind uf(n);

        for(auto road: roads) {
            uf.unionByRank(road[0], road[1], road[2]);
        }

        int res = uf.getMinScore(1);
        return res;

    }
};