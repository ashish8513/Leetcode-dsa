// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".


/**
 * @param {string} s
 * @return {number}
 */
var countPalindromicSubsequence = function(s) {
//new set to store unique palindromes
    let set = new Set();

    for (let char of new Set(s)) {
//find the first and last index of the current char -(to look weather palindrome is possible or not -- |first middle last| -- first must be equal to last)
        let firstIndex = s.indexOf(char);
        let lastIndex = s.lastIndexOf(char);
//is to check weather both are not pointing to same or consecutive element as we cannot create palindrome from it
        if (lastIndex - firstIndex > 1) {
//get all the possible letters for middle
            let uniqueChars = new Set(s.slice(firstIndex + 1, lastIndex));
//add it to the set
            for (let middle of uniqueChars) {
                set.add(`${char}${middle}${char}`);
            }
        }
    }
    
    return set.size;
};
