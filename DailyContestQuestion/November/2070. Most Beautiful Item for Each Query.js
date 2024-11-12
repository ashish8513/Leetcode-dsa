// You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.

// You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.

// Return an array answer of the same length as queries where answer[j] is the answer to the jth query.


/**
 * @param {number[][]} items
 * @param {number[]} queries
 * @return {number[]}
 */
var maximumBeauty = function(items, queries) {
    items.sort((a, b) => a[0] - b[0]);
let maxBeauty = 0;
let prefixMaxBeauty = [];
for (let [price, beauty] of items) {
  prefixMaxBeauty.push((maxBeauty = Math.max(maxBeauty, beauty)));
}
let answer = [];
for (let queryPrice of queries) {
  let low = 0;
  let high = items.length - 1;
  while (low <= high) {
    let mid = ~~(low / 2 + high / 2);
    if (items[mid][0] <= queryPrice) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  answer.push(high >= 0 ? prefixMaxBeauty[high] : 0);
}
return answer;
};