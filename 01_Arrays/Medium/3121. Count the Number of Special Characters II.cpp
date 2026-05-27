// 3121. Count the Number of Special Characters II
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a string word. A letter c is called special if it appears both in lowercase and uppercase in word, and every lowercase occurrence of c appears before the first uppercase occurrence of c.

// Return the number of special letters in word.


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);

        // store positions
        for(int i = 0; i < word.size(); i++) {

            char ch = word[i];

            if(ch >= 'a' && ch <= 'z') {
                lastLower[ch - 'a'] = i;
            }
            else {
                if(firstUpper[ch - 'A'] == -1)
                    firstUpper[ch - 'A'] = i;
            }
        }

        int count = 0;

        // check condition
        for(int i = 0; i < 26; i++) {

            if(lastLower[i] != -1 &&
               firstUpper[i] != -1 &&
               lastLower[i] < firstUpper[i]) {

                count++;
            }
        }

        return count;
    }
};