// There are n teams numbered from 0 to n - 1 in a tournament; each team is also a node in a DAG.

// You are given the integer n and a 0-indexed 2D integer array edges of length m representing the DAG, where edges[i] = [ui, vi] indicates that there is a directed edge from team ui to team vi in the graph.

// A directed edge from a to b in the graph means that team a is stronger than team b and team b is weaker than team a.

// Team a will be the champion of the tournament if there is no team b that is stronger than team a.

// Return the team that will be the champion of the tournament if there is a unique champion, otherwise, return -1.

/**
 * @param {number} n
 * @param {number[][]} edges
 * @return {number}
 */
var findChampion = function(n, edges) {
    let weakerTeam = new Set();
    for([strong,weak] of edges){
        weakerTeam.add(weak);
    }
    let res = [];
    for(let i=0;i<n;i++){
       if(!weakerTeam.has(i)){
        res.push(i);
       }
    }
    return res.length === 1 ? res[0] :-1;
};