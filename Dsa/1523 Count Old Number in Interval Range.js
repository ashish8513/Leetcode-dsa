// Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).


/**
 * @param {number} low
 * @param {number} high
 * @return {number}
 */
function countOdds(low, high) {
    return Math.floor((high + 1) / 2) - Math.floor(low / 2);
}
