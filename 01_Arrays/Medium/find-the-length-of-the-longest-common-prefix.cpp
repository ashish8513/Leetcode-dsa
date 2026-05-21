// You are given two arrays with positive integers arr1 and arr2.

// A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.

// A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have common prefixes 565 and 5655 while 1223 and 43456 do not have a common prefix.

// You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.

// Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_set<string> st;

        // store all prefixes of arr1 numbers
        for(int num : arr1) {
            string s = to_string(num);
            string pref = "";

            for(char ch : s) {
                pref += ch;
                st.insert(pref);
            }
        }

        int ans = 0;

        // check prefixes from arr2
        for(int num : arr2) {
            string s = to_string(num);
            string pref = "";

            for(char ch : s) {
                pref += ch;

                if(st.count(pref)) {
                    ans = max(ans, (int)pref.size());
                }
            }
        }

        return ans;
    }
};