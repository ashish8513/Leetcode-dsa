// Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n = s.length();
        
   
        int total = 1 << k;
        
        for(int i = 0; i <= n - k; i++) {
            st.insert(s.substr(i, k));
            
        
            if(st.size() == total)
                return true;
        }
        
        return st.size() == total;
    }
};
