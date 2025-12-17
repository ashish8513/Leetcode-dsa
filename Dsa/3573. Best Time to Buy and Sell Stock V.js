// You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.

// You are allowed to make at most k transactions, where each transaction can be either of the following:

// Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].

// Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].

// Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.

// Return the maximum total profit you can earn by making at most k transactions.

/**
 * @param {number[]} prices
 * @param {number} k
 * @return {number}
 */
var maximumProfit = function (prices, k) {
      const n = prices.length;
    const buy = Array(k + 1).fill(-Infinity);
    const sell = Array(k + 1).fill(-Infinity);
    const done = Array(k + 1).fill(0);

    for (let price of prices) {
        for (let t = k; t >= 1; t--) {
            buy[t] = Math.max(buy[t], done[t - 1] - price);
            sell[t] = Math.max(sell[t], done[t - 1] + price);

            done[t] = Math.max(
                done[t],
                buy[t] + price,
                sell[t] - price
            );
        }
    }

    return done[k];
};
