// Max Absolute Diff of Two Subarrays

// Given an array of integers arr[], 
// find two non-overlapping contiguous sub-arrays such that the absolute difference between the sum of two sub-arrays is maximum.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxDiffSubArrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> rightMax(n), rightMin(n);

        // Right Maximum
        int curMax = arr[n - 1];
        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            curMax = max(arr[i], arr[i] + curMax);
            rightMax[i] = max(rightMax[i + 1], curMax);
        }

        // Right Minimum
        int curMin = arr[n - 1];
        rightMin[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            curMin = min(arr[i], arr[i] + curMin);
            rightMin[i] = min(rightMin[i + 1], curMin);
        }

        int leftCurMax = arr[0], leftBestMax = arr[0];
        int leftCurMin = arr[0], leftBestMin = arr[0];

        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            if (i > 0) {
                leftCurMax = max(arr[i], leftCurMax + arr[i]);
                leftBestMax = max(leftBestMax, leftCurMax);

                leftCurMin = min(arr[i], leftCurMin + arr[i]);
                leftBestMin = min(leftBestMin, leftCurMin);
            }

            ans = max(ans, abs(leftBestMax - rightMin[i + 1]));
            ans = max(ans, abs(leftBestMin - rightMax[i + 1]));
        }

        return ans;
    }
};