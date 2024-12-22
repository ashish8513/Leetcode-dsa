// You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.

// If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].

// You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi.

// Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.



/**
 * @param {number[]} heights
 * @param {number[][]} queries
 * @return {number[]}
 */
var leftmostBuildingQueries = function(heights, queries) {
    var res = Array(queries.length).fill(-1);
    var queue = Array(heights.length).fill().map(() => []);
    var pq = new MinPriorityQueue();

    // Step 1: If highest height itself is answer
    queries.forEach(([i,j], index) => {
        if(i===j) res[index] = i;
        else if (i < j && heights[i] < heights[j]) res[index] = j;
        else if (i > j && heights[i] > heights[j]) res[index] = i;
        // Step 2: If highest element is not the answer
        else queue[Math.max(i,j)].push([Math.max(heights[i],heights[j]),index]);
    });

    // Step 3: Push all element in MinPriorityQueue and pop it if current height is valid for it
    for(var i=0; i<heights.length; ++i) {
        while(!pq.isEmpty() && pq.front().element[0] < heights[i]) res[pq.dequeue().element[1]] = i;
        queue[i].forEach(x => pq.enqueue(x, x[0]));
    }
    return res;
};