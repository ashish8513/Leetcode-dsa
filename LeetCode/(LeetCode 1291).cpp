//? 1291. Sequential Digits
// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.
#include <iostream>
#include <vector>
#include <string> 

using namespace std;

class Solution {
public:
    int len(int n){
        int count=0;
        while(n){
            n/=10;
            count++;
        }
        return count;
    }
    string s="123456789";
    vector<int> sequentialDigits(int low, int high) {
        int lowLen=len(low);
        int highLen=len(high);
        vector<int> ans;
        for(int len=lowLen;len<=highLen;len++){
            for(int i=0;i<9-len+1;i++){
                int num=stoi(s.substr(i,len));
                if(num>=low and num<=high) ans.push_back(num);
            }
        }
        return ans;
    }
};