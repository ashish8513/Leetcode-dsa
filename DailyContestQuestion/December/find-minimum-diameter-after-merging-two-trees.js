// There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

// You must connect one node from the first tree with another node from the second tree with an edge.

// Return the minimum possible diameter of the resulting tree.

// The diameter of a tree is the length of the longest path between any two nodes in the tree.

/**
 * @param {number[][]} edges1
 * @param {number[][]} edges2
 * @return {number}
 */
var minimumDiameterAfterMerge = function (edges1, edges2) {
    let x = treeDiameter(edges1);
    let y = treeDiameter(edges2);
    return Math.max(x, Math.max(y, Math.floor((x + 1) / 2) + Math.floor((y + 1) / 2) + 1));
};

var treeDiameter = function (edges) {
    let n = edges.length + 1;
    if (n === 1) {
        return 0;
    }

    let g = new Map();
    let ans = 0;

    for (let e of edges) {
        let [u, v] = e;
        if (!g.has(u)) g.set(u, new Set());
        if (!g.has(v)) g.set(v, new Set());
        g.get(u).add(v);
        g.get(v).add(u);
    }

    let vis = new Array(n + 1).fill(false);
    let next = edges[0][0];

    dfs(next, 0);
    vis = new Array(n + 1).fill(false);
    dfs(next, 0);

    return ans;

    function dfs(u, t) {
        if (vis[u]) {
            return;
        }
        vis[u] = true;
        if (ans < t) {
            ans = t;
            next = u;
        }
        for (let v of g.get(u)) {
            dfs(v, t + 1);
        }
    }
};