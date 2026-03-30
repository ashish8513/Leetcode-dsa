// You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.

// You can apply the following operation on any of the two strings any number of times:

// Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
// Return true if you can make the strings s1 and s2 equal, and false otherwise.


class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even(26, 0), odd(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            if (i % 2 == 0) {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (even[i] != 0 || odd[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
