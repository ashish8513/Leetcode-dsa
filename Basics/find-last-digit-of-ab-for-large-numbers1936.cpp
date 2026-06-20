// Given two integers a and b in the form of strings. Return the last digit of ab.
#include <iostream>
#include <string>
using namespace std;
class Solution {
  public:
    int getLastDigit(string& a, string& b) {
        
        if (b == "0")
            return 1;
            
        int base = a.back() - '0';
        
        int exp = 0;
        for (char ch : b) {
            exp = (exp * 10 + (ch - '0')) % 4;
        }
        
        if (exp == 0)
            exp = 4;
            
        int ans = 1;
        for (int i = 0; i < exp; i++) {
            ans = (ans * base) % 10;
        }
        
        return ans;
    }
};