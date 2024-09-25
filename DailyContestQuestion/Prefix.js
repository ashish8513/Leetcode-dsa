// You are given an array words of size n consisting of non-empty strings.

// We define the score of a string word as the number of strings words[i] such that word is a prefix of words[i].

// For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
// Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].

// Note that a string is considered as a prefix of itself.

class Trie {
    constructor() {
        this.children = {};
        this.cnt = 0;
    }

    insert(w) {
        let node = this;
        for (const c of w) {
            if (!node.children[c]) {
                node.children[c] = new Trie();
            }
            node = node.children[c];
            node.cnt++;
        }
    }

    search(w) {
        let node = this;
        let ans = 0;
        for (const c of w) {
            if (!node.children[c]) {
                return ans;
            }
            node = node.children[c];
            ans += node.cnt;
        }
        return ans;
    }
}

/**
 * @param {string[]} words
 * @return {number[]}
 */
var sumPrefixScores = function (words) {
    const trie = new Trie();
    for (const w of words) {
        trie.insert(w);
    }
    return words.map(w => trie.search(w));
};
 