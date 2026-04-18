// You are given an integer n.

// Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.

// Return an integer denoting the mirror distance of n​​​​​​​.

// abs(x) denotes the absolute value of x.
/**
 * @param {number} n
 * @return {number}
 */
let mirrorDistance = function (n) {
    let rev = 0, num = n

    while (num > 0) {
        let digit = num % 10;
        rev = rev * 10 + digit;
        num = Math.floor(num / 10)
    }

    return Math.abs(n - rev)
}
