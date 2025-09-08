// No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

// Given an integer n, return a list of two integers [a, b] where:

// a and b are No-Zero integers.
// a + b = n
// The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

 

/**
 * @param {number} n
 * @return {number[]}
 */
var getNoZeroIntegers = function(n) {
    let a, b;
    for (let i = 1; i < n; i++) {
        b = n - i;
        a = i;
        if (String(a).indexOf('0') == -1 && String(b).indexOf('0') == -1) break;
    }
    return [a, b];
};