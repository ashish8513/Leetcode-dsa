//? Shortest Unique Prefix for Every Word

// Given an array of strings arr[ ], find the shortest prefix of each string that uniquely identifies it among all strings in the array. A prefix is unique if it is not a prefix of any other string in the array.

// Note: No string in the given array is a prefix of another string.

class TrieNode {
public:
    TrieNode* child[26];
    int cnt;

    TrieNode() {
        cnt = 0;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(string &word) {
        TrieNode* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->child[idx] == NULL)
                node->child[idx] = new TrieNode();

            node = node->child[idx];
            node->cnt++;
        }
    }

    string getPrefix(string &word) {
        TrieNode* node = root;
        string ans = "";

        for (char ch : word) {
            int idx = ch - 'a';
            node = node->child[idx];
            ans += ch;

            if (node->cnt == 1)
                break;
        }

        return ans;
    }

    vector<string> findPrefixes(vector<string>& arr) {

        for (string &word : arr)
            insert(word);

        vector<string> ans;

        for (string &word : arr)
            ans.push_back(getPrefix(word));

        return ans;
    }
};