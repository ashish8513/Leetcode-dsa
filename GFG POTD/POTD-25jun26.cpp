//? N-Digit Numbers with Increasing Digits
// Given an integer n, return all the n digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void solve(int len, int n, int num, int last, vector<int>& ans) {
        if (len == n) {
            ans.push_back(num);
            return;
        }

        for (int d = last + 1; d <= 9; d++) {
            solve(len + 1, n, num * 10 + d, d, ans);
        }
    }

    vector<int> increasingNumbers(int n) {
        vector<int> ans;

        if (n == 1)
            ans.push_back(0);

        for (int d = 1; d <= 9; d++) {
            solve(1, n, d, d, ans);
        }

        return ans;
    }
};