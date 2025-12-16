// You are given an integer n, representing the number of employees in a company. Each employee is assigned a unique ID from 1 to n, and employee 1 is the CEO. You are given two 1-based integer arrays, present and future, each of length n, where:

// present[i] represents the current price at which the ith employee can buy a stock today.
// future[i] represents the expected price at which the ith employee can sell the stock tomorrow.
// The company's hierarchy is represented by a 2D integer array hierarchy, where hierarchy[i] = [ui, vi] means that employee ui is the direct boss of employee vi.

// Additionally, you have an integer budget representing the total funds available for investment.

// However, the company has a discount policy: if an employee's direct boss purchases their own stock, then the employee can buy their stock at half the original price (floor(present[v] / 2)).

// Return the maximum profit that can be achieved without exceeding the given budget.

// Note:

// You may buy each stock at most once.
// You cannot use any profit earned from future stock prices to fund additional investments and must buy only from budget.


/**
 * @param {number} n
 * @param {number[]} present
 * @param {number[]} future
 * @param {number[][]} hierarchy
 * @param {number} budget
 * @return {number}
 */
var maxProfit = function(n, present, future, hierarchy, budget) {
         const dp = Array.from({ length: n + 1 }, () =>
    Array.from({ length: 2 }, () => new Array(budget + 1).fill(0))
  );

  const children = Array.from({ length: n + 1 }, () => []);
  const deg = new Array(n + 1).fill(0);
  const parent = new Array(n + 1).fill(0);
  for (const [p, c] of hierarchy) {
    children[p].push(c);
    deg[p]++;
    parent[c] = p;
  }
  const queue = [];
  for (let i = 1; i <= n; i++) {
    if (deg[i] === 0) queue.push(i);
  }

  let qi = 0;
  while (qi < queue.length) {
    const curr = queue[qi++];

    for (let s = 0; s <= 1; s++) {
      const price = present[curr - 1] >> s;
      let skip = new Array(budget + 1).fill(0);
      let take = new Array(budget + 1).fill(Number.NEGATIVE_INFINITY);

      for (let b = price; b <= budget; b++) {
        take[b] = future[curr - 1] - price;
      }
      for (const child of children[curr]) {
        const dpChildSkip = dp[child][0];
        const dpChildTake = dp[child][1];

        const newSkip = new Array(budget + 1).fill(Number.NEGATIVE_INFINITY);
        const newTake = new Array(budget + 1).fill(Number.NEGATIVE_INFINITY);

        for (let b = 0; b <= budget; b++) {
          if (skip[b] !== Number.NEGATIVE_INFINITY) {
            const maxSpend = Math.min(budget - b, budget);
            for (let spend = 0; spend <= maxSpend; spend++) {
              newSkip[b + spend] = Math.max(
                newSkip[b + spend],
                skip[b] + dpChildSkip[spend]
              );
            }
          }

          if (take[b] !== Number.NEGATIVE_INFINITY) {
            const maxSpend = Math.min(budget - b, budget);
            for (let spend = 0; spend <= maxSpend; spend++) {
              newTake[b + spend] = Math.max(
                newTake[b + spend],
                take[b] + dpChildTake[spend]
              );
            }
          }
        }

        skip = newSkip;
        take = newTake;
      }
      for (let b = 0; b <= budget; b++) {
        dp[curr][s][b] = Math.max(skip[b], take[b]);
      }
    }

    const p = parent[curr];
    if (p !== 0 && --deg[p] === 0) {
      queue.push(p);
    }
  }

  return dp[1][0][budget];
};
