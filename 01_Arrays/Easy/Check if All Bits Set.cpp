// Given a number n, check whether every bit in the binary representation of the given number is set or not.

// Return true if yes, otherwise false.
class Solution {
public:
    bool isBitSet(int n) {
        return n > 0 && ((n & (n + 1)) == 0);
    }
};