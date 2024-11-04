// Given a string word, compress it using the following algorithm:

// Begin with an empty string comp. While word is not empty, use the following operation:
// Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
// Append the length of the prefix followed by c to comp.
// Return the string comp.


/**
 * @param {string} word
 * @return {string}
 */
var compressedString = function(word) {
    let comp = "";
      let cnt = 1, n = word.length;
      let ch = word[0];
      for (let i = 1; i < n; i++) {
          if (word[i] === ch && cnt < 9) {
              cnt++;
          } else {
              comp += cnt + ch;
              ch = word[i];
              cnt = 1;
          }
      }
      comp += cnt + ch;
      return comp;
};