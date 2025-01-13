// You are given a string s.

// You can perform the following process on s any number of times:

// Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
// Delete the closest character to the left of index i that is equal to s[i].
// Delete the closest character to the right of index i that is equal to s[i].
// Return the minimum length of the final string s that you can achieve.


/**
 * @param {string} s
 * @return {number}
 */
var minimumLength = function (s) {

    const freqMap = new Map(), N = s.length;

    // Consider the frequency of all characters
    for (let i = 0; i < N; i++) {
        const char = s[i];
        if (!freqMap.has(char)) {
            freqMap.set(char, 0);
        }
        freqMap.set(char, freqMap.get(char) + 1);
    }

    // Iterate over the freqMap
    let length = 0;
    freqMap.forEach((value, key) => {
        length += value % 2 === 0 ? 2 : 1;
    });

    return length;
};