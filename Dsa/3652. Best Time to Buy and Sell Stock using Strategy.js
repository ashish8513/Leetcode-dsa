// You are given two integer arrays prices and strategy, where:

// prices[i] is the price of a given stock on the ith day.
// strategy[i] represents a trading action on the ith day, where:
// -1 indicates buying one unit of the stock.
// 0 indicates holding the stock.
// 1 indicates selling one unit of the stock.
// You are also given an even integer k, and may perform at most one modification to strategy. A modification consists of:

// Selecting exactly k consecutive elements in strategy.
// Set the first k / 2 elements to 0 (hold).
// Set the last k / 2 elements to 1 (sell).
// The profit is defined as the sum of strategy[i] * prices[i] across all days.

// Return the maximum possible profit you can achieve.

// Note: There are no constraints on budget or stock ownership, so all buy and sell operations are feasible regardless of past actions.


/**
 * @param {number[]} prices
 * @param {number[]} strategy
 * @param {number} k
 * @return {number}
 */
var maxProfit = function(prices, strategy, k) {
    const n = prices.length;
    let profitSum = new Array(n+1).fill(0)  
    let pricesSum = new Array(n+1).fill(0)  

    for(let i=0; i<n; i++){
        profitSum[i+1] = profitSum[i] + prices[i] * strategy[i]
        pricesSum[i+1] = pricesSum[i] + prices[i] 
    }

    let res = profitSum[n] 

    const half = k/2 

   
    for(let i=0; i+k<=n; i++){
        const leftProfit = profitSum[i] 
        const rightProfit = profitSum[n] - profitSum[i+k] 
        const changedProfit = pricesSum[i+k] - pricesSum[i+half] 

        res = Math.max(res, leftProfit + changedProfit + rightProfit)
    }
    return res
};
