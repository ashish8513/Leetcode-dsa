// A string s is called happy if it satisfies the following conditions:

// s only contains the letters 'a', 'b', and 'c'.
// s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// s contains at most a occurrences of the letter 'a'.
// s contains at most b occurrences of the letter 'b'.
// s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

// A substring is a contiguous sequence of characters within a string.

/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {string}
 */
function longestDiverseString(a, b, c) {
    let ans = [];
    let store = [
        ['a', a],
        ['b', b],
        ['c', c],
    ];
    
    while (true) {
        store.sort((a, b) => b[1] - a[1]);
        let hasNext = false;
        
        for (let i = 0; i < store.length; i++) {
            let [ch, ctn] = store[i];
            if (ctn < 1) {
                break;
            }
            const n = ans.length;
            if (n >= 2 && ans[n - 1] === ch && ans[n - 2] === ch) {
                continue;
            }
            hasNext = true;
            ans.push(ch);
            store[i][1] -= 1;
            break;
        }
        
        if (!hasNext) {
            break;
        }
    }
    
    return ans.join('');
}
