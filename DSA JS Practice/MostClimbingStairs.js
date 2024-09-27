// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

/**
 * @param {number[]} cost
 * @return {number}
 */
function minCostClimbingStairs(cost) {
    const n = cost.length;
    const f = Array(n).fill(-1);
    const dfs = i => {
        if (i >= n) {
            return 0;
        }
        if (f[i] < 0) {
            f[i] = cost[i] + Math.min(dfs(i + 1), dfs(i + 2));
        }
        return f[i];
    };
    return Math.min(dfs(0), dfs(1));
}