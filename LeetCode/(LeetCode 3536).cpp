//? 3536. Maximum Product of Two Digits

// You are given a positive integer n.

// Return the maximum product of any two digits in n.

// Note: You may use the same digit twice if it appears more than once in n.
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int first = -1, second = -1;

        while (n > 0) {
            int d = n % 10;

            if (d >= first) {
                second = first;
                first = d;
            } else if (d > second) {
                second = d;
            }

            n /= 10;
        }

        return first * second;
    }
};