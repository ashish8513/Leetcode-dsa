//? 3302. Find the Lexicographically Smallest Valid Sequence
// You are given two strings word1 and word2.

// A string x is called almost equal to y if you can change at most one character in x to make it identical to y.

// A sequence of indices seq is called valid if:

// The indices are sorted in ascending order.
// Concatenating the characters at these indices in word1 in the same order results in a string that is almost equal to word2.
// Return an array of size word2.length representing the lexicographically smallest valid sequence of indices. If no such sequence of indices exists, return an empty array.

// Note that the answer must represent the lexicographically smallest array, not the corresponding string formed by those indices.

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int N=word1.size();
        int M=word2.size();
        int R=M-1;
        int C=0;
        vector<int> Right(N);
        for(int i=N-1;i>=0;i--){
            Right[i]=C;
            if(R>=0 && word1[i]==word2[R]){
                R--;
                C++;
            }
        }
        vector<int> ans;
        bool changed=false;
        int j=0;
        for(int i=0;i<N && j<M;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!changed && Right[i]>=M-1-j){
                ans.push_back(i);
                j++;
                changed=true;
            }
        }
        if(j==M){
            return ans;
        }
        return {};
    }
};