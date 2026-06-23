//? 3699. Number of ZigZag Arrays I
// You are given three integers n, l, and r.

// A ZigZag array of length n is defined as follows:

// Each element lies in the range [l, r].
// No two adjacent elements are equal.
// No three consecutive elements form a strictly increasing or strictly decreasing sequence.
// Return the total number of valid ZigZag arrays.

// Since the answer may be large, return it modulo 109 + 7.

// A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

// A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1'000'000'007;

        int m = r - l + 1;

        vector<long long> up(m + 1), down(m + 1);

        // Length = 2
        for (int v = 1; v <= m; v++) {
            up[v] = v - 1;
            down[v] = m - v;
        }

        for (int len = 2; len < n; len++) {
            vector<long long> newUp(m + 1), newDown(m + 1);

            long long pref = 0;
            for (int v = 1; v <= m; v++) {
                newUp[v] = pref;
                pref = (pref + down[v]) % MOD;
            }

            long long suff = 0;
            for (int v = m; v >= 1; v--) {
                newDown[v] = suff;
                suff = (suff + up[v]) % MOD;
            }

            up = move(newUp);
            down = move(newDown);
        }

        long long ans = 0;
        for (int v = 1; v <= m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }

        return (int)ans;
    }
};