// Given two positive integers n and k, the binary string Sn is formed as follows:

// S1 = "0"
// Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
// Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

// For example, the first four strings in the above sequence are:

// S1 = "0"
// S2 = "011"
// S3 = "0111001"
// S4 = "011100110110001"
// Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

/**
 * @param {number} n
 * @param {number} k
 * @return {character}
 */
const findKthBit = (n, k) => {
    function invertAndReverse(s) {
        let inverted = '';
        for (let char of s) {
            inverted += char === '0' ? '1' : '0';
        }
        return inverted.split('').reverse().join('');
    }
    
    function findBit(n, k) {
        if (n === 1) {
            return '0';
        }

        const len = (1 << n) - 1; 
        const mid = (len + 1) >> 1; 

        if (k === mid) {
            return '1';
        } else if (k < mid) {
            return findBit(n - 1, k);
        } else {
            const mirrorPos = mid - (k - mid);
            const bit = findBit(n - 1, mirrorPos);
            return bit === '0' ? '1' : '0';
        }
    }

    return findBit(n, k);
}