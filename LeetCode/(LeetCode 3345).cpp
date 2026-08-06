//? 3345. Smallest Divisible Digit Product I
// You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

class Solution {
public:
    int digitProduct(int num) {
        int product = 1;
        while (num > 0) {
            product *= (num % 10);
            num /= 10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        while (true) {
            if (digitProduct(n) % t == 0)
                return n;
            n++;
        }
    }
};