//  Choose and Swap

// Given a string s of lowercase English letters, you can swap all occurrences of any two distinct characters at most once. Return the lexicographically smallest string after this operation.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    string chooseSwap(string &s) {
        // code here
        vector<int> first(26, -1);

        // Store first occurrence of every character
        for (int i=0; i<s.size(); i++) 
        {
            if(first[(s[i]-'a')] == -1)
            {
                first[s[i]-'a'] = i;
            }
        }

        for (int i=0; i<s.size(); i++) 
        {
            int curr = s[i]-'a';
            for (int ch=0; ch<curr; ch++) 
            {
                if (first[ch] > i) {
                    char c1 = s[i];
                    char c2 = ch + 'a';

                    for (char &c : s) {
                        if (c == c1)
                        {
                            c = c2;
                        }
                        else if (c == c2)
                        {
                            c = c1;
                        }
                    }
                    return s;
                }
            }
        }

        return s;
    }
}; 