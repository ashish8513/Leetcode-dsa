// You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.

// Return the lexicographically largest repeatLimitedString possible.

// A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.

 /**
 * @param {string} s
 * @param {number} repeatLimit
 * @return {string}
 */
var repeatLimitedString = function(s, repeatLimit) {
    let count = {};
    let array = Array.from(s);

    array.forEach(char => {
        count[char] = (count[char] || 0) + 1;
    });

    let sortedKeys = Object.keys(count).sort((a, b) => b.localeCompare(a));
    let result = [];

    while (sortedKeys.length > 0) {
        let char = sortedKeys.shift();
        let repeat = Math.min(count[char], repeatLimit);

        for (let i = 0; i < repeat; i++) {
            result.push(char);
        }
        count[char] -= repeat;

        if (count[char] > 0) {
            if (sortedKeys.length > 0) {
                let nextChar = sortedKeys.shift();
                result.push(nextChar);
                count[nextChar]--;

                if (count[nextChar] > 0) {
                    sortedKeys.unshift(nextChar);
                }

                sortedKeys.unshift(char);
            } else {
                break;
            }
        }
    }

    return result.join('');
};
