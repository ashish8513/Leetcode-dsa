// 567. Permutation in String
// Solved
// Medium
// Topics
// Companies
// Hint
// Given two strings s1 and s2, return true if s2 contains a 
// permutation
//  of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.


function checkInclusion(s1, s2) {
    const len_s1 = s1.length;
    const len_s2 = s2.length;
  
    if (len_s1 > len_s2) {
      return false;
    }
  
    const freq_s1 = new Map();
    const freq_window = new Map();
  
    // Build frequency maps for s1 and the window in s2
    for (let char of s1) {
      freq_s1.set(char, (freq_s1.get(char) || 0) + 1);
    }
  
    for (let i = 0; i < len_s1; i++) {
      const char = s2[i];
      freq_window.set(char, (freq_window.get(char) || 0) + 1);
    }
  
    // Compare initial frequency maps
    if (areMapsEqual(freq_s1, freq_window)) {
      return true;
    }
  
    // Sliding window approach
    for (let i = len_s1; i < len_s2; i++) {
      const char_out = s2[i - len_s1];
      if (freq_window.get(char_out) === 1) {
        freq_window.delete(char_out);
      } else {
        freq_window.set(char_out, freq_window.get(char_out) - 1);
      }
  
      const char_in = s2[i];
      freq_window.set(char_in, (freq_window.get(char_in) || 0) + 1);
  
      // Compare frequency maps
      if (areMapsEqual(freq_s1, freq_window)) {
        return true;
      }
    }
  
    return false;
  }
  
  function areMapsEqual(map1, map2) {
    if (map1.size !== map2.size) {
      return false;
    }
  
    for (let [key, value] of map1) {
      if (value !== map2.get(key)) {
        return false;
      }
    }
  
    return true;
  }
  
  // Test case
  const s1 = "ab";
  const s2 = "eidbaooo";
  const result = checkInclusion(s1, s2);
  console.log(result); // Expected output: true