// A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

// It is ().
// It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
// It can be written as (A), where A is a valid parentheses string.
// You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

// If locked[i] is '1', you cannot change s[i].
// But if locked[i] is '0', you can change s[i] to either '(' or ')'.
// Return true if you can make s a valid parentheses string. Otherwise, return false.

/**
 * @param {string} s
 * @param {string} locked
 * @return {boolean}
 */

var canBeValid = function (s, locked) {
    if (s.length % 2 !== 0) return false; 
    let open = 0;

    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(' || locked[i] === '0') open++;
        else open--;

        if (open < 0) return false; 
    }
    open = 0;
    for (let i = s.length - 1; i >= 0; i--) {
        if (s[i] === ')' || locked[i] === '0') open++;
        else open--;

        if (open < 0) return false; 
    }

    return true;
};