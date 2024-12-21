// There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

// You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.

// A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by k, where the value of a connected component is the sum of the values of its nodes.

// Return the maximum number of components in any valid split.


/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} values
 * @param {number} k
 * @return {number}
 */
var maxKDivisibleComponents = function(n, edges, values, k) {
    if (!edges.length) return 1
    let res = 0
    let graph = {}
    // Create the graph
    for (const [a, b] of edges){
        if (!graph[a]){
            graph[a] = [b]
        } else {
            graph[a].push(b)
        }
        if (!graph[b]){
            graph[b] = [a]
        } else {
            graph[b].push(a)
        }
    }
    // The set of visited vertices
    const visited = new Set()
    iter(0)
    return res

    function iter(v){
        visited.add(v)
        let currSum = values[v] 
        for (const next of graph[v]){
            if (!visited.has(next)){
                currSum += iter(next)
            }
        }
        if (currSum % k === 0) res++
        return currSum
    }
};