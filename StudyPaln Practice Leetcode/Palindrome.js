// Given an integer x, return true if x is a 
// palindrome
// , and false otherwise.
/**
 * @param {number} x
 * @return {boolean}
 */
function isPalindrome(x) {
    // Convert the number to a string
    const str = x.toString();
    
    // Reverse the string and compare it with the original
    const reversedStr = str.split('').reverse().join('');
    
    // Return true if both are equal, otherwise false
    return str === reversedStr;
}