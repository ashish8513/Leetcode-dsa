// 1963. Minimum Number of Swaps to Make the String Balanced
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.
// A string is called balanced if and only if:
// It is the empty string, or
// It can be written as AB, where both A and B are balanced strings, or
// It can be written as [C], where C is a balanced string.
// You may swap the brackets at any two indices any number of times.
// Return the minimum number of swaps to make s balanced.

function minSwaps(s) {
    let x = 0;
    for (const c of s) {
        if (c === '[') {
            ++x;
        } else if (x) {
            --x;
        }
    }
    return (x + 1) >> 1;
}

// /** * @param {string} s * @return {number} */ function minSwaps(s) { let imbalance = 0; let swaps = 0; for (let i = 0; i < s.length; i++) { if (s[i] === '[') { imbalance++; } else { imbalance--; } if (imbalance < 0) { swaps++; imbalance = 0; } } return swaps; }


