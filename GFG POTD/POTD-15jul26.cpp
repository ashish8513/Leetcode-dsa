//? Longest Bitonic Subarray

// Given an array arr[] of size n containing positive integers, return the maximum length of the bitonic subarray.

// A subarray arr[i...j] is considered bitonic if its elements first monotonically increase, and then monotonically decrease. Formally, there exists and index k (where i <= k <= j) such that:

// arr[i] <= arr[i+1] <= . . . <= arr[k] 
// arr[k] >= arr[k+1] >= . . . >= arr[j]
#include <bits/std++.h>
using namespace std;

class Solution {
public:
    int bitonic(vector<int> &arr) {
        int n = arr.size();

        if (n == 0)
            return 0;

        vector<int> inc(n, 1), dec(n, 1);

        // Longest Non-Decreasing ending at i
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1])
                inc[i] = inc[i - 1] + 1;
        }

        // Longest Non-Increasing starting from i
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[i + 1])
                dec[i] = dec[i + 1] + 1;
        }

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, inc[i] + dec[i] - 1);
        }

        return ans;
    }
};