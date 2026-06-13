// You are given an array of strings words, where each string represents a word containing lowercase English letters.

// You are also given an integer array weights of length 26, where weights[i] represents the weight of the ith lowercase English letter.

// The weight of a word is defined as the sum of the weights of its characters.

// For each word, take its weight modulo 26 and map the result to a lowercase English letter using reverse alphabetical order (0 -> 'z', 1 -> 'y', ..., 25 -> 'a').

// Return a string formed by concatenating the mapped characters for all words in order.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for (string &word : words) {
            int sum = 0;

            for (char ch : word) {
                sum += weights[ch - 'a'];
            }

            int mod = sum % 26;
            ans.push_back('z' - mod);
        }

        return ans;
    }
}; 