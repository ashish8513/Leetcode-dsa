
//? Substrings with more 1's than 0's

// Given a binary string s consists only of 0s and 1s. Calculate the number of substrings that have more 1s than 0s.
#include <iostream>
#include <vector>
using namespace std;

class Fenwick {
public:
    vector<int> bit;
    int n;

    Fenwick(int sz) {
        n = sz;
        bit.assign(n + 1, 0);
    }

    void update(int idx) {
        while (idx <= n) {
            bit[idx]++;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    long long countSubstring(string s) {
        int n = s.size();

        int offset = n + 2;
        Fenwick bit(2 * n + 5);

        int pref = 0;
        long long ans = 0;

        // prefix sum = 0
        bit.update(offset);

        for (char c : s) {
            if (c == '1')
                pref++;
            else
                pref--;

            int idx = pref + offset;

            // Count previous prefix sums < current prefix
            ans += bit.query(idx - 1);

            bit.update(idx);
        }

        return ans;
    }
};