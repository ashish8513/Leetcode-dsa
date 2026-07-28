//? 3517. Smallest Palindromic Rearrangement I
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given a palindromic string s.

// Return the lexicographically smallest palindromic permutation of s.
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string left = "";
        string mid = "";

        for (int i = 0; i < 26; i++) {
            left += string(freq[i] / 2, char('a' + i));

            if (freq[i] % 2 == 1)
                mid = char('a' + i);
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};