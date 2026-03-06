// Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

class Solution {
public:
    bool checkOnesSegment(string s) {
        return (s.find("01")>s.length());
    }
};
