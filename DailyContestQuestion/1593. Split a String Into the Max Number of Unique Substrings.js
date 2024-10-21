/**
 * @param {string} s
 * @return {number}
 */
var maxUniqueSplit = function(s) {
    let maxCount = 0;
    
    const backtrack = (index, seen) => {
        if (index === s.length) {
            maxCount = Math.max(maxCount, seen.size);
            return;
        }
        
        let currentSubstring = '';
        for (let i = index; i < s.length; i++) {
            currentSubstring += s[i];
            if (!seen.has(currentSubstring)) {
                seen.add(currentSubstring);
                backtrack(i + 1, seen);
                seen.delete(currentSubstring); // backtrack step
            }
        }
    };
    
    backtrack(0, new Set());
    return maxCount;
};

// Example usage:
console.log(maxUniqueSplit("ababccc")); // Output: 5
 