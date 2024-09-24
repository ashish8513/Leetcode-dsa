// You are given two arrays with positive integers arr1 and arr2.
// A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.
// A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have a common prefix 565 while 1223 and 43456 do not have a common prefix.
// You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.
// Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.

var longestCommonPrefix = function(arr1, arr2) {
    let maxLength = 0;

    // Helper function to find the common prefix between two strings
    function commonPrefix(str1, str2) {
        let i = 0;
        while (i < str1.length && i < str2.length && str1[i] === str2[i]) {
            i++;
        }
        return i; // Return the length of the common prefix
    }

    // Compare every pair of numbers (x, y) from arr1 and arr2
    for (let x of arr1) {
        for (let y of arr2) {
            const strX = x.toString();
            const strY = y.toString();
            const commonLen = commonPrefix(strX, strY); // Find the length of the common prefix
            maxLength = Math.max(maxLength, commonLen); // Keep track of the longest prefix length
        }
    }

    return maxLength;
}

// Example usage:
const arr1 = [5655359, 1223, 78];
const arr2 = [56554, 43456, 789];

console.log(longestCommonPrefix(arr1, arr2)); // Output should be 3 (common prefix is "565")



//? write method to code in the javaScript




var longestCommonPrefix = function (arr1, arr2) {
    const s = new Set();
    for (let x of arr1) {
        for (; x; x = Math.floor(x / 10)) {
            s.add(x);
        }
    }
    let ans = 0;
    for (let x of arr2) {
        for (; x; x = Math.floor(x / 10)) {
            if (s.has(x)) {
                ans = Math.max(ans, Math.floor(Math.log10(x)) + 1);
            }
        }
    }
    return ans;
};