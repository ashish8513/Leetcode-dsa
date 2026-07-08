//? 3756. Concatenate Non-Zero Digits and Multiply by Sum II

// You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].

// For each queries[i], extract the substring s[li..ri]. Then, perform the following:

// Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
// Let sum be the sum of digits in x. The answer is x * sum.
// Return an array of integers answer where answer[i] is the answer to the ith query.

// Since the answers may be very large, return them modulo 109 + 7.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
private:
    static constexpr int MOD = 1000000007;
    static constexpr int MAX = 100001;
    inline static int pow[MAX];

    inline static int init = []() {
        pow[0] = 1;
        for (int i = 1; i < MAX; i++)
            pow[i] = pow[i - 1] * 10LL % MOD;
        return 0;
    }();

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        
        vector<int> A(n + 1, 0);
        vector<int> B(n + 1, 0);
        vector<int> ln(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            A[i + 1] = A[i] + d;
            B[i + 1] = d ? (B[i] * 10LL + d) % MOD : B[i];
            ln[i + 1] = ln[i] + (d > 0);
        }

        vector<int> res;
        res.reserve(queries.size());

        for (auto& q : queries) {
            int l = q[0], r = q[1] + 1;

            long long sub = B[l] * 1LL * pow[ln[r] - ln[l]] % MOD;
            long long x = (B[r] - sub + MOD) % MOD;

            res.push_back(x * (A[r] - A[l]) % MOD);
        }

        return res;
    }
};