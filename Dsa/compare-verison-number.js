
// Code
// Testcase
// Test Result
// Test Result
// 165. Compare Version Numbers
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given two version strings, version1 and version2, compare them. A version string consists of revisions separated by dots '.'. The value of the revision is its integer conversion ignoring leading zeros.

// To compare version strings, compare their revision values in left-to-right order. If one of the version strings has fewer revisions, treat the missing revision values as 0.

// Return the following:

// If version1 < version2, return -1.
// If version1 > version2, return 1.
// Otherwise, return 0.

/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
    let v1 = version1.split('.').map(Number)
    let v2 = version2.split('.').map(Number)

    let maxLength = Math.max(v1.length, v2.length);

    for (let i=0; i<maxLength;i++){
        let num1 = v1[i] || 0; 
        let num2 = v2[i] || 0;
    
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
    }
  return 0
};