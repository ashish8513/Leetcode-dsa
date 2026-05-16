// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
   int minSubArrayLen(int tar, vector<int>& a) {
        int n = a.size();
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < n; ++right) {
            sum += a[right];

            // shrink window while valid
            while (sum >= tar) {
                minLen = min(minLen, right - left + 1);
                sum -= a[left];
                ++left;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    cout << sol.minSubArrayLen(7, nums1) << endl; // Output: 2
    
    vector<int> nums2 = {1, 4, 4};
    cout << sol.minSubArrayLen(4, nums2) << endl; // Output: 1
    
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << sol.minSubArrayLen(11, nums3) << endl; // Output: 0
    
    return 0;
}