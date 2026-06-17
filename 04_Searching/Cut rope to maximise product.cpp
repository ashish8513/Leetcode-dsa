// Given a rope of length n meters, cut it into multiple smaller ropes such that the product of their lengths is maximized. At least one cut is mandatory.
#include <iostream>
using namespace std;

class Solution {
public:
    long long maxProduct(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;

        long long ans = 1;

        while (n > 4) {
            ans *= 3;
            n -= 3;
        }

        return ans * n;
    }
}; 