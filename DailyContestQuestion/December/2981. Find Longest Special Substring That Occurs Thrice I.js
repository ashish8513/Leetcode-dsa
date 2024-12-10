// You are given a string s that consists of lowercase English letters.

// A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.

// Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.

// A substring is a contiguous non-empty sequence of characters within a string.


/**
 * @param {string} s
 * @return {number}
 */
var maximumLength = function (s) {
    let left = 0;
    let right = 0;
    let maxLength = -1;
    const map = new Map();
  
    while (right <= s.length) {
      if (s[right] === s[left]) {
        right++;
      } else {
        let length = right - left;
        let index = 0;
  
        while (index < length) {
          const substr = s.substring(left, left + index + 1);
          const currentCount = map.get(substr) ?? 0;
          const newCount = currentCount + length - index;
          if (newCount >= 3) {
            maxLength = Math.max(maxLength, substr.length);
          }
          map.set(substr, newCount);
          index++;
        }
  
        while (s[left] !== s[right]) {
          left++;
        }
      }
    }
  
    return maxLength;
  };