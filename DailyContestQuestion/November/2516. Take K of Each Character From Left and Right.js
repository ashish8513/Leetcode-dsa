// You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.

// Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.


/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var takeCharacters = function(s, k) {
    const cnt = new Array(3).fill(0)
    const check = () => cnt.every((item) => item >= k)
    for(let i = 0; i < s.length; i++) {
        cnt[s[i].charCodeAt(0) - 97]++
    }
    if(!check()) return -1
    let res = s.length
    let j = s.length - 1
    for(let i = s.length - 1; i >= 0; i--) {
        cnt[s[i].charCodeAt(0) - 97]--
        while(!check()) {
            cnt[s[j].charCodeAt(0) - 97]++
            j--
        }
        res = Math.min(res, i + (s.length - j - 1))
    }
    return res
};