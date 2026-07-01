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

        int noSkip = arr[0];
        int oneSkip = INT_MIN;
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            int prevNoSkip = noSkip;

            noSkip = max(noSkip + arr[i], arr[i]);

            oneSkip = max(prevNoSkip, oneSkip + arr[i]);

            ans = max(ans, max(noSkip, oneSkip));
        }

        return ans;
    }
};