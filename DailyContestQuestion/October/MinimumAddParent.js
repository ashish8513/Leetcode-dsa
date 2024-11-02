// 921. Minimum Add to Make Parentheses Valid
// Solved
// Medium
// Topics
// Companies
// A parentheses string is valid if and only if:

// It is the empty string,
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

// For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
// Return the minimum number of moves required to make s valid.
/**
 * @param {string} s
 * @return {number}
 */
function minAddToMakeValid(s) {
    const stk = [];
    for (const c of s) {
        if (c === ')' && stk.length > 0 && stk[stk.length - 1] === '(') {
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.length;
}
