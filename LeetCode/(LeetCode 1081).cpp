//? 1081. Smallest Subsequence of Distinct Characters
// Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.


class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> vis(26, false);

        // Count frequency
        for (char c : s)
            freq[c - 'a']++;

        string st;

        for (char c : s) {
            freq[c - 'a']--;

            // Already included
            if (vis[c - 'a'])
                continue;

            // Maintain increasing lexicographical order
            while (!st.empty() &&
                   st.back() > c &&
                   freq[st.back() - 'a'] > 0) {
                vis[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            vis[c - 'a'] = true;
        }

        return st;
    }
};