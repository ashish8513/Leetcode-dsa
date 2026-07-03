//? Ways to Increase LCS by One
// Given two strings s1 and s2 consisting of lowercase English letters of length n1 and n2 respectively, find the number of ways to insert exactly one character into string s1 such that the length of the Longest Common Subsequence (LCS) of both strings increases by exactly 1.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        // pref[i][j] = LCS of s1[0..i-1] and s2[0..j-1]
        vector<vector<int>> pref(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1])
                    pref[i][j] = pref[i - 1][j - 1] + 1;
                else
                    pref[i][j] = max(pref[i - 1][j], pref[i][j - 1]);
            }
        }

        int L = pref[n1][n2];

        // suf[i][j] = LCS of s1[i..] and s2[j..]
        vector<vector<int>> suf(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    suf[i][j] = suf[i + 1][j + 1] + 1;
                else
                    suf[i][j] = max(suf[i + 1][j], suf[i][j + 1]);
            }
        }

        int ans = 0;

        // Try every insertion position
        for (int pos = 0; pos <= n1; pos++) {
            bool ok[26] = {false};

            // Match inserted character with every occurrence in s2
            for (int j = 0; j < n2; j++) {
                if (pref[pos][j] + 1 + suf[pos][j + 1] == L + 1) {
                    ok[s2[j] - 'a'] = true;
                }
            }

            for (int c = 0; c < 26; c++)
                if (ok[c]) ans++;
        }

        return ans;
    }
}; 