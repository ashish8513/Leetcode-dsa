// You are given a string s of even length consisting of digits from 0 to 9, and two integers a and b.

// You can apply either of the following two operations any number of times and in any order on s:

// Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back to 0. For example, if s = "3456" and a = 5, s becomes "3951".
// Rotate s to the right by b positions. For example, if s = "3456" and b = 1, s becomes "6345".
// Return the lexicographically smallest string you can obtain by applying the above operations any number of times on s.

// A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "0158" is lexicographically smaller than "0190" because the first position they differ is at the third letter, and '5' comes before '9'.


/**
 * @param {string} s
 * @param {number} a
 * @param {number} b
 * @return {string}
 */
const performeAdding = (s, a) => s.split('').map((v, i) => i & 1 ? (+v + a) % 10 : v).join('');
var findLexSmallestString = function(s, a, b) {
    const allStrings = new Set();
    const appendAllOperations = (str) => {
        if (allStrings.has(str)) {
            return;
        }
        allStrings.add(str);
        appendAllOperations(performeAdding(str, a));
        appendAllOperations(str.slice(b) + str.slice(0, b));
    }
    appendAllOperations(s);
    return [...allStrings].reduce((a, b) => a < b ? a : b);
};