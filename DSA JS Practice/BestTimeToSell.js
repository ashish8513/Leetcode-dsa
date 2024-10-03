// 121. Best Time to Buy and Sell Stock
// Easy
// Topics
// Companies
// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let ans=0;
    let mi=prices[0];
       for (const v of prices) {
        ans = Math.max(ans, v - mi);
        mi = Math.min(mi, v);
    }
    return ans

};