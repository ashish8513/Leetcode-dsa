// 2696. Minimum String Length After Removing Substrings
// Solved
// Easy
// Topics
// Companies
// Hint
// You are given a string s consisting only of uppercase English letters.

// You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.

// Return the minimum possible length of the resulting string that you can obtain.

// Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.
/**
 * @param {string} s
 * @return {number}
 */
function minLength(s) {
    const stack = [];

    for (let i = 0; i < s.length; i++) {
        const currentChar = s[i];
        if (stack.length > 0) {
            const topChar = stack[stack.length - 1];
            if ((topChar === 'A' && currentChar === 'B') || (topChar === 'C' && currentChar === 'D')) {
                stack.pop();  
            } else {
                stack.push(currentChar);  
            }
        } else {
            stack.push(currentChar);  
        }
    }

    return stack.length; 
}
