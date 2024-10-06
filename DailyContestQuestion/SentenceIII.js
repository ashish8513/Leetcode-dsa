    // // Check common prefix
    // 1813. Sentence Similarity III
    // Solved
    // Medium
    // Topics
    // Companies
    // Hint
    // You are given two strings sentence1 and sentence2, each representing a sentence composed of words. A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of only uppercase and lowercase English characters.
    
    // Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty) inside one of these sentences such that the two sentences become equal. Note that the inserted sentence must be separated from existing words by spaces.

    /**
 * @param {string} sentence1
 * @param {string} sentence2
 * @return {boolean}
 */
function areSentencesSimilar(sentence1, sentence2) {
    const words1 = sentence1.split(' ');
    const words2 = sentence2.split(' ');
    
    let i = 0; 
    let j = 0; 
    
    while (i < words1.length && i < words2.length && words1[i] === words2[i]) {
        i++;
    }

    while (j < words1.length - i && j < words2.length - i && words1[words1.length - 1 - j] === words2[words2.length - 1 - j]) {
        j++;
    }

    return i + j >= Math.min(words1.length, words2.length);
}
