// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned)

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {

        bool negative = false;

        if(x < 0){
            negative = true;
            x = -x;
        }

        string s = to_string(x);

        std::reverse(s.begin(), s.end());

        long long ans = stoll(s);

        if(negative)
            ans = -ans;

        // overflow check
        if(ans > INT_MAX || ans < INT_MIN)
            return 0;

        return ans;
    }
};