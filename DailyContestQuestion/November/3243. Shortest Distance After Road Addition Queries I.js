// You are given an integer n and a 2D integer array queries.

// There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.

// queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.

// Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.


/**
 * @param {number} n
 * @param {number[][]} queries
 * @return {number[]}
 */
var shortestDistanceAfterQueries = function (n, queries) {
    let shortestPaths = new Array(queries.length);

    let graph = [];
    //O(n)
    for (let j = 0; j < n - 1; j++) {
        graph[j] = [j + 1];
    }
    graph[n - 1] = [];

    //O(Q)
    for (let i = 0; i < queries.length; i++) {

        graph[queries[i][0]].push(queries[i][1])

        //O(1)
        let set = new Set();
        //distance,node
        set.add([0, 0]);

        let distance = new Array(n).fill(Infinity);
        distance[0] = 0;

        //O(V+E)
        while (set.size) {
            let top = [...set][0];
            let pDist = top[0];
            let parentNode = top[1];

            //O(1)
            set.delete(top);

            for (let neighbour of graph[parentNode]) {
                if (pDist + 1 < distance[neighbour]) {
                    if (distance[neighbour] != Infinity) {
                        set.delete([distance[neighbour], neighbour])
                    }
                    distance[neighbour] = pDist + 1;
                    set.add([distance[neighbour], neighbour])
                }
            }

        }


        shortestPaths[i] = distance[n - 1];


    }

    return shortestPaths;
};