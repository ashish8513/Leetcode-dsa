// You are given an array of integers nums. Perform the following steps:

// Find any two adjacent numbers in nums that are non-coprime.
// If no such numbers are found, stop the process.
// Otherwise, delete the two numbers and replace them with their LCM (Least Common Multiple).
// Repeat this process as long as you keep finding two adjacent non-coprime numbers.
// Return the final modified array. It can be shown that replacing adjacent non-coprime numbers in any arbitrary order will lead to the same result.

// The test cases are generated such that the values in the final array are less than or equal to 108.

// Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the Greatest Common Divisor of x and y.


/**
 * @param {number[]} nums
 * @return {number[]}
 */
let replaceNonCoprimes = function (nums) {
    const stack = [];
    const gcd = (a, b) => {
        while (b !== 0) {
            const t = b;
            b = a % b;
            a = t;
        }

        return a;
    };

    for (let num of nums) {
        while (stack.length > 0) {
            const top = stack[stack.length - 1];
            const g = gcd(top, num);
            if (g === 1) break;
            stack.pop();
            num = (top / g) * num;
        }

        stack.push(num);
    }

    return stack;
}