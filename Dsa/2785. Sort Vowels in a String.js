// Given a 0-indexed string s, permute s to get a new string t such that:

// All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
// The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
// Return the resulting string.

// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.



/**
 * @param {string} s
 * @return {string}
 */
var sortVowels = function(s) {
    const vowels = 'AEIOUaeiou' // KEY IDEA: vowels are already in sorted order
    const frq = new Array(10).fill(0) // frequency map for vowels

    // count how many times each vowel appears
    for(let i = 0; i < s.length; i++){
        if(vowels.indexOf(s[i]) !== -1){
            frq[vowels.indexOf(s[i])]++
        }
    }

    let str = ''
    let frqIndex = 0
    for(let i = 0; i < s.length; i++){
        // non-vowel -> keep it in place
        if(vowels.indexOf(s[i]) === -1){

            str += s[i]

        } else {
            // find the next available vowel in sorted order
            while(frq[frqIndex] === 0){
                frqIndex++
            }

            str += vowels[frqIndex]
            frq[frqIndex]--
        }
    }


    return str
};