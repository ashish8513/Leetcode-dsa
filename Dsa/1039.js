// You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.

// Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.

// You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.

// Return the minimum possible score that you can achieve with some triangulation of the polygon.

/**
 * @param {number[]} values
 * @return {number}
 */
var minScoreTriangulation = function(values) {
    let dp = Array(values.length).fill().map((i) => Array(values.length).fill(0));
    function dfs(i, j) {
        if (dp[i][j]) return dp[i][j];
        if (j - i < 2) return 0;
        let min = Infinity;
        // k forms a triangle with i and j, thus bisecting the array into two parts
        // These two parts become two subproblems that can be solved recursively
        for (let k = i + 1; k < j; k++) {
            let sum = values[i] * values[j] * values[k] + dfs(i, k) + dfs(k, j);
            min = Math.min(min, sum);
        }
        return dp[i][j] = min;
    }
    return dfs(0, values.length - 1);
};