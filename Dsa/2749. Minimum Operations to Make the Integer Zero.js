// You are given two integers num1 and num2.

// In one operation, you can choose integer i in the range [0, 60] and subtract 2i + num2 from num1.

// Return the integer denoting the minimum number of operations needed to make num1 equal to 0.

// If it is impossible to make num1 equal to 0, return -1.

/**
* @param {number} num1
* @param {number} num2
* @return {number}
*/
const makeTheIntegerZero = (num1, num2) => {
    const countOnes = n => n.toString(2).replace(/0/g, '').length;

    for (let k = 1; k <= 60; k++) {
        let d = num1 - num2 * k;
        if (d < k) return -1;
        if (k >= countOnes(d)) return k;
    }

    return -1;
}