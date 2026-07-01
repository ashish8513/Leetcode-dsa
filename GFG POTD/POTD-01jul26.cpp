//? Max Subarray Sum by Removing At Most One
// Given an array arr[], find the maximum sum of a non-empty subarray. You are allowed to skip at most one element in the subarray.

// Note: After skipping the element, the subarray must still be non-empty.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();

        if (n == 1)
            return arr[0];

        vector<int> fw(n), bw(n);

        fw[0] = arr[0];
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            fw[i] = max(arr[i], fw[i - 1] + arr[i]);
            ans = max(ans, fw[i]);
        }

        bw[n - 1] = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            bw[i] = max(arr[i], bw[i + 1] + arr[i]);
        }

        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, fw[i - 1] + bw[i + 1]);
        }

        return ans;
    }
};