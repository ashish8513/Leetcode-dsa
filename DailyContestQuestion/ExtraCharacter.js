// You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

// Return the minimum number of extra characters left over if you break up s optimally.


function minExtraChar(s, dictionary) {
    const n = s.length;
    const dp = new Array(n + 1).fill(Infinity);
    dp[0] = 0;

    // Set for quick lookup of dictionary words
    const dictSet = new Set(dictionary);

    // Iterate through the string
    for (let i = 0; i < n; i++) {
        // Case where we skip the current character (count it as an extra character)
        dp[i + 1] = Math.min(dp[i + 1], dp[i] + 1);

        // Check substrings starting from index i
        for (let j = i + 1; j <= n; j++) {
            const word = s.slice(i, j);
            if (dictSet.has(word)) {
                dp[j] = Math.min(dp[j], dp[i]);
            }
        }
    }

    // Return the minimum number of extra characters at the end of the string
    return dp[n];
}

// Example usage:
const s = "applepenapple";
const dictionary = ["apple", "pen"];
console.log(minExtraChar(s, dictionary)); // Output: 0, since "applepenapple" can be broken perfectly
