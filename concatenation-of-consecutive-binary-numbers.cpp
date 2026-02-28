// Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.


class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, MOD = 1e9 + 7, len = 0;
        for (int i = 1; i <= n; i++) {
            if (__builtin_popcount(i) == 1) len++;
            ans = ((ans << len) % MOD + i) % MOD;
        }
        return ans;
    }
};
