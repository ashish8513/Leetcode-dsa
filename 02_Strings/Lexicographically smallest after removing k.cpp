// Given a string s consisting of n lowercase characters. Return the lexicographically smallest string after removing exactly k characters from the string. But you have to correct the value of k, i.e., if the length of the string is a power of 2, reduce k by half, else multiply k by 2. You can remove any k characters.

// Note: If it is not possible to remove k (the value of k after correction) characters or if the resulting string is empty return -1.

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string lexicographicallySmallest(string s, int k) {
        int n = s.size();

        // Correct k
        if ((n & (n - 1)) == 0)      // n is power of 2
            k /= 2;
        else
            k *= 2;

        if (k > n || k == n)
            return "-1";

        int remove = k;
        vector<char> st;

        for (char ch : s) {
            while (!st.empty() && remove > 0 && st.back() > ch) {
                st.pop_back();
                remove--;
            }
            st.push_back(ch);
        }

        while (remove > 0) {
            st.pop_back();
            remove--;
        }

        string ans(st.begin(), st.end());

        return ans.empty() ? "-1" : ans;
    }
};