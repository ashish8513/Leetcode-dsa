// 8. Length of Last Word
// Solved
// Easy
// Topics
// Companies
// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal 
// substring
//  consisting of non-space characters only.

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
    let i = s.length - 1;
    while (i >= 0 && s[i] === ' ') {
        --i;
    }
    let j = i;
    while (j >= 0 && s[j] !== ' ') {
        --j;
    }
    return i - j;
};