// You are given two arrays of strings wordsContainer and wordsQuery.

// For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.

// Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// --- Approach 1: Brute Force ---
class Solution1 {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsQuery.size();
        int n = wordsContainer.size();
        vector<int> ans(m);
        
        for (int q = 0; q < m; q++) {
            string query = wordsQuery[q];
            int bestIndex = -1;
            int maxSuffixLen = -1;
            int bestWordLen = INT_MAX;
            
            for (int i = 0; i < n; i++) {
                string word = wordsContainer[i];
                int suffixLen = 0;
                int qIdx = query.length() - 1;
                int wIdx = word.length() - 1;
                
                while (qIdx >= 0 && wIdx >= 0 && query[qIdx] == word[wIdx]) {
                    suffixLen++;
                    qIdx--; wIdx--;
                }
                
                if (suffixLen > maxSuffixLen || 
                   (suffixLen == maxSuffixLen && word.length() < bestWordLen)) {
                    maxSuffixLen = suffixLen;
                    bestWordLen = word.length();
                    bestIndex = i;
                }
            }
            ans[q] = bestIndex;
        }
        return ans;
    }
};

// --- Approach 2: Suffix Extraction + Binary Search (String) ---
class Solution2 {
    struct SuffixData {
        string str;
        int wordLen;
        int wordIdx;
    };
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<SuffixData> suffixList;
        int globalBestIdx = -1;
        int globalBestLen = INT_MAX;
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            string word = wordsContainer[i];
            int len = word.length();
            if (len < globalBestLen) {
                globalBestLen = len;
                globalBestIdx = i;
            }
            for (int j = 0; j < len; j++) {
                suffixList.push_back({word.substr(j), len, i});
            }
        }
        
        sort(suffixList.begin(), suffixList.end(), [](const SuffixData& a, const SuffixData& b) {
            if (a.str != b.str) return a.str < b.str;
            if (a.wordLen != b.wordLen) return a.wordLen < b.wordLen;
            return a.wordIdx < b.wordIdx;
        });
        
        int m = wordsQuery.size();
        vector<int> ans(m);
        
        for (int q = 0; q < m; q++) {
            string query = wordsQuery[q];
            int bestMatch = globalBestIdx;
            
            for (int j = 0; j < query.length(); j++) {
                string qSuffix = query.substr(j);
                int low = 0, high = suffixList.size() - 1, bestPos = -1;
                
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (suffixList[mid].str == qSuffix) {
                        bestPos = mid;
                        high = mid - 1; // Find the first occurrence
                    } else if (suffixList[mid].str < qSuffix) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                
                if (bestPos != -1) {
                    bestMatch = suffixList[bestPos].wordIdx;
                    break;
                }
            }
            ans[q] = bestMatch;
        }
        return ans;
    }
};

// --- Approach 3: Suffix Extraction + Binary Search (Combined Hash) ---
class Solution3 {
    struct SuffixData {
        long long combinedHash;
        int wordLen;
        int wordIdx;
    };
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<SuffixData> suffixList;
        long long P1 = 313, P2 = 317;
        long long MOD1 = 1000000007, MOD2 = 1000000009;
        
        int globalBestIdx = -1, globalBestLen = INT_MAX;
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            string word = wordsContainer[i];
            int len = word.length();
            if (len < globalBestLen) { globalBestLen = len; globalBestIdx = i; }
            
            long long hash1 = 0, hash2 = 0, power1 = 1, power2 = 1;
            for (int j = len - 1; j >= 0; j--) {
                char ch = word[j];
                hash1 = (hash1 + ch * power1) % MOD1;
                hash2 = (hash2 + ch * power2) % MOD2;
                power1 = (power1 * P1) % MOD1;
                power2 = (power2 * P2) % MOD2;
                
                long long combined = (hash1 << 32) | (hash2 & 0xFFFFFFFFLL);
                suffixList.push_back({combined, len, i});
            }
        }
        
        sort(suffixList.begin(), suffixList.end(), [](const SuffixData& a, const SuffixData& b) {
            if (a.combinedHash != b.combinedHash) return a.combinedHash < b.combinedHash;
            if (a.wordLen != b.wordLen) return a.wordLen < b.wordLen;
            return a.wordIdx < b.wordIdx;
        });
        
        vector<int> ans(wordsQuery.size());
        for (int q = 0; q < wordsQuery.size(); q++) {
            string query = wordsQuery[q];
            int bestMatch = globalBestIdx;
            int qLen = query.length();
            
            vector<long long> qHashes(qLen);
            long long hash1 = 0, hash2 = 0, power1 = 1, power2 = 1;
            for (int j = qLen - 1; j >= 0; j--) {
                char ch = query[j];
                hash1 = (hash1 + ch * power1) % MOD1;
                hash2 = (hash2 + ch * power2) % MOD2;
                power1 = (power1 * P1) % MOD1;
                power2 = (power2 * P2) % MOD2;
                qHashes[j] = (hash1 << 32) | (hash2 & 0xFFFFFFFFLL);
            }
            
            for (int j = 0; j < qLen; j++) {
                long long targetHash = qHashes[j];
                int low = 0, high = suffixList.size() - 1, bestPos = -1;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (suffixList[mid].combinedHash == targetHash) {
                        bestPos = mid; high = mid - 1;
                    } else if (suffixList[mid].combinedHash < targetHash) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if (bestPos != -1) {
                    bestMatch = suffixList[bestPos].wordIdx;
                    break;
                }
            }
            ans[q] = bestMatch;
        }
        return ans;
    }
};

// --- Approach 4: HashMap with String Suffixes ---
class Solution4 {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        unordered_map<string, int> suffixMap;
        int globalBestIdx = -1, globalBestLen = INT_MAX;
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            string word = wordsContainer[i];
            int len = word.length();
            if (len < globalBestLen) { globalBestLen = len; globalBestIdx = i; }
            
            for (int j = 0; j < len; j++) {
                string suffix = word.substr(j);
                if (suffixMap.find(suffix) == suffixMap.end()) {
                    suffixMap[suffix] = i;
                } else {
                    int existingIdx = suffixMap[suffix];
                    int existingLen = wordsContainer[existingIdx].length();
                    if (len < existingLen) {
                        suffixMap[suffix] = i;
                    }
                }
            }
        }
        
        vector<int> ans(wordsQuery.size());
        for (int q = 0; q < wordsQuery.size(); q++) {
            string query = wordsQuery[q];
            int bestMatch = globalBestIdx;
            
            for (int j = 0; j < query.length(); j++) {
                string qSuffix = query.substr(j);
                if (suffixMap.find(qSuffix) != suffixMap.end()) {
                    bestMatch = suffixMap[qSuffix];
                    break;
                }
            }
            ans[q] = bestMatch;
        }
        return ans;
    }
};

// --- Approach 5: HashMap with Rolling Hash ---
class Solution5 {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        unordered_map<long long, int> suffixMap;
        long long P = 313;
        int globalBestIdx = -1, globalBestLen = INT_MAX;
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            string word = wordsContainer[i];
            int len = word.length();
            if (len < globalBestLen) { globalBestLen = len; globalBestIdx = i; }
            
            long long hash = 0;
            for (int j = len - 1; j >= 0; j--) {
                hash = hash * P + word[j];
                if (suffixMap.find(hash) == suffixMap.end()) {
                    suffixMap[hash] = i;
                } else {
                    int existingIdx = suffixMap[hash];
                    int existingLen = wordsContainer[existingIdx].length();
                    if (len < existingLen) {
                        suffixMap[hash] = i;
                    }
                }
            }
        }
        
        vector<int> ans(wordsQuery.size());
        for (int q = 0; q < wordsQuery.size(); q++) {
            int bestMatch = globalBestIdx;
            long long hash = 0;
            string query = wordsQuery[q];
            
            for (int j = query.length() - 1; j >= 0; j--) {
                hash = hash * P + query[j];
                if (suffixMap.find(hash) != suffixMap.end()) {
                    bestMatch = suffixMap[hash];
                } else {
                    break;
                }
            }
            ans[q] = bestMatch;
        }
        return ans;
    }
};

// --- Approach 6: The Ultimate Suffix Trie (Optimal) ---
class Solution {
    struct TrieNode {
        TrieNode* children[26];
        int bestIdx;
        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            bestIdx = -1;
        }
    };
    
    TrieNode* root;
    vector<string>* container;

    void updateBestIdx(TrieNode* node, int newIdx) {
        if (node->bestIdx == -1) {
            node->bestIdx = newIdx;
        } else {
            int oldLen = (*container)[node->bestIdx].length();
            int newLen = (*container)[newIdx].length();
            if (newLen < oldLen || (newLen == oldLen && newIdx < node->bestIdx)) {
                node->bestIdx = newIdx;
            }
        }
    }

    void add(string& word, int wordIdx) {
        TrieNode* curr = root;
        updateBestIdx(curr, wordIdx);
        for (int j = word.length() - 1; j >= 0; j--) {
            int charIdx = word[j] - 'a';
            if (curr->children[charIdx] == nullptr) {
                curr->children[charIdx] = new TrieNode();
            }
            curr = curr->children[charIdx];
            updateBestIdx(curr, wordIdx);
        }
    }

    int query(string& q) {
        TrieNode* curr = root;
        for (int j = q.length() - 1; j >= 0; j--) {
            int charIdx = q[j] - 'a';
            if (curr->children[charIdx] == nullptr) {
                break;
            }
            curr = curr->children[charIdx];
        }
        return curr->bestIdx;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        root = new TrieNode();
        container = &wordsContainer;
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            add(wordsContainer[i], i);
        }
        
        vector<int> ans(wordsQuery.size());
        for (int q = 0; q < wordsQuery.size(); q++) {
            ans[q] = query(wordsQuery[q]);
        }
        return ans;
    }
};