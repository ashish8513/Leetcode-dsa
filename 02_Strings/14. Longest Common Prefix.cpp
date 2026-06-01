// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.empty()){
            return "";
        }
        string prefix="";
        for (int i = 0; i <= strs[0].size(); i++)
        {
            char ch=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(i>=strs[j].size() || strs[j][i] !=ch){
                    return prefix;
                }
            }
            prefix +=ch;
        }
        return prefix;
    }
};