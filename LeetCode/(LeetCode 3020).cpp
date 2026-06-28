//? 3020. Find the Maximum Number of Elements in Subset

// You are given an array of positive integers nums.

// You need to select a subset of nums which satisfies the following condition:

// You can place the selected elements in a 0-indexed array such that it follows the pattern: [x, x2, x4, ..., xk/2, xk, xk/2, ..., x4, x2, x] (Note that k can be be any non-negative power of 2). For example, [2, 4, 16, 4, 2] and [3, 9, 3] follow the pattern while [2, 4, 8, 4, 2] does not.
// Return the maximum number of elements in a subset that satisfies these conditions.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Special case for 1
        if (freq.count(1)) {
            if (freq[1] % 2 == 0)
                ans = max(ans, freq[1] - 1);
            else
                ans = max(ans, freq[1]);
        }

        for (auto &[x, cnt] : freq) {
            if (x == 1)
                continue;

            long long cur = x;
            int len = 0;

            while (true) {
                if (freq[cur] >= 2) {
                    len += 2;

                    __int128 nxt = (__int128)cur * cur;

                    // Agar next value long long se bahar chali jaye
                    if (nxt > LLONG_MAX) {
                        len--;          // peak exist nahi karega
                        break;
                    }

                    cur = (long long)nxt;
                } else {
                    if (freq[cur] >= 1)
                        len++;          // peak
                    else if (len > 0)
                        len--;          // last pair invalid
                    break;
                }
            }

            ans = max(ans, len);
        }

        return ans;
    }
};