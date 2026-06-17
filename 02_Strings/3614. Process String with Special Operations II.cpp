// You are given a string s consisting of lowercase English letters and the special characters: '*', '#', and '%'.

// You are also given an integer k.

// Build a new string result by processing s according to the following rules from left to right:

// If the letter is a lowercase English letter append it to result.
// A '*' removes the last character from result, if it exists.
// A '#' duplicates the current result and appends it to itself.
// A '%' reverses the current result.
// Return the kth character of the final string result. If k is out of the bounds of result, return '.'.
#include <iostream>
using namespace std;
 class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;

        // Compute final length
        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                len++;
            }
            else if (ch == '*') {
                if (len > 0) len--;
            }
            else if (ch == '#') {
                len *= 2;
            }
            else if (ch == '%') {
                // length unchanged
            }

            len = min(len, (long long)4e18); // avoid overflow
        }

        if (k >= len) return '.';

        // Reverse process
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                if (k == len - 1) return ch;
                len--;
            }
            else if (ch == '*') {
                len++;
            }
            else if (ch == '#') {
                long long oldLen = len / 2;
                k %= oldLen;
                len = oldLen;
            }
            else if (ch == '%') {
                k = len - 1 - k;
            }
        }

        return '.';
    }
};