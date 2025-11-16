// Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.

/**
 * @param {string} s
 * @return {number}
 */
var numSub = (s) =>
    s.split("0").reduce((sum, b) =>
        (sum + b.length * (b.length + 1) / 2) % 1_000_000_007,
        0);
