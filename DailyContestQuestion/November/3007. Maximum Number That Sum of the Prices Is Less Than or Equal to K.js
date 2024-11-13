// 3007. Maximum Number That Sum of the Prices Is Less Than or Equal to K
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an integer k and an integer x. The price of a number num is calculated by the count of 
// set bits
//  at positions x, 2x, 3x, etc., in its binary representation, starting from the least significant bit. The following table contains examples of how price is calculated.

// x	num	Binary Representation	Price
// 1	13	000001101	3
// 2	13	000001101	1
// 2	233	011101001	3
// 3	13	000001101	1
// 3	362	101101010	2
// The accumulated price of num is the total price of numbers from 1 to num. num is considered cheap if its accumulated price is less than or equal to k.

// Return the greatest cheap number.

/**
 * @param {number} k
 * @param {number} x
 * @return {number}
 */
const count = (k, rightmost, x) => {
    if (k < rightmost) return 0;
  
    let n = 1, bits = rightmost, p = 1;
  
    const getAccPrice = (p, n) => 2 * bits + (p % x === 0 ? n : 0);
  
    while (getAccPrice(p, n) <= k) {
      bits = getAccPrice(p++, n);
      n *= 2; 
    }
  
    return n + count(k - bits, rightmost + (p % x === 0), x);
  }
  
  function findMaximumNumber(k, x) {
    return count(k, 0, x) - 1; 
  }