// We define the lcp matrix of any 0-indexed string word of n lowercase English letters as an n x n grid such that:

// lcp[i][j] is equal to the length of the longest common prefix between the substrings word[i,n-1] and word[j,n-1].
// Given an n x n matrix lcp, return the alphabetically smallest string word that corresponds to lcp. If there is no such string, return an empty string.

// A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "aabd" is lexicographically smaller than "aaca" because the first position they differ is at the third letter, and 'b' comes before 'c'.


class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }

        string word(n, '\0');
        char current = 'a';

        for (int i = 0; i < n; i++) {
            if (word[i] == '\0') {
                if (current > 'z') return "";
                word[i] = current;

                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        word[j] = word[i];
                    }
                }
                current++;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] != word[j]) {
                    if (lcp[i][j] != 0) return "";
                } else {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) return "";
                    } else {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) return "";
                    }
                }
            }
        }

        return word;
    }
};
