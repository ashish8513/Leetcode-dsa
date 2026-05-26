// 3120. Count the Number of Special Characters I
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

// Return the number of special letters in word.

 

// Example 1:

// Input: word = "aaAbcBC"

// Output: 3

// Explanation:

// The special characters in word are 'a', 'b', and 'c'.

// Example 2:

// Input: word = "abc"

// Output: 0

// Explanation:

// No character in word appears in uppercase.

// Example 3:

// Input: word = "abBCab"

// Output: 1

// Explanation:

// The only special character in word is 'b'.
#include <iostream>
#include <string>
using namespace std;
 class Solution {
public:
    int numberOfSpecialChars(string word) {

        int count = 0;

        // check every character from a to z
        for(char ch = 'a'; ch <= 'z'; ch++) {

            bool small = false;
            bool capital = false;

            // traverse whole string
            for(char c : word) {

                if(c == ch)
                    small = true;

                if(c == toupper(ch))
                    capital = true;
            }

            // both exist
            if(small && capital)
                count++;
        }

        return count;
    }
};