//? 1967. Number of Strings That Appear as Substrings in Word

// Given an array of strings patterns and a string word, return the number of strings in patterns that exist as a substring in word.

// A substring is a contiguous sequence of characters within a string.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;

        for (string &pat : patterns) {
            if (word.find(pat) != string::npos)
                cnt++;
        }

        return cnt;
    }
};