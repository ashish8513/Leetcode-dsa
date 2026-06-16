// You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

// Build a new string result by processing s according to the following rules from left to right:

// If the letter is a lowercase English letter append it to result.
// A '*' removes the last character from result, if it exists.
// A '#' duplicates the current result and appends it to itself.
// A '%' reverses the current result.
// Return the final string result after processing all characters in s.
#include<iostream>
using namespace std;

 class Solution {
public:
    string processStr(string s) {
        string result;

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                result += ch;
            }
            else if (ch == '*') {
                if (!result.empty()) {
                    result.pop_back();
                }
            }
            else if (ch == '#') {
                result += result;
            }
            else if (ch == '%') {
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
}; 