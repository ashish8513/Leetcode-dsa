// Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

// Note: A subarray is a contiguous part of any given array.

// Examples:

// Input: arr[] = [100, 200, 300, 400], k = 2
// Output: 700
// Explanation: arr2 + arr3 = 700, which is maximum.
// Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
// Output: 39
// Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.
// Input: arr[] = [100, 200, 300, 400], k = 1
// Output: 400
// Explanation: arr3 = 400, which is maximum.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    int maxSubarraySum(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (n < k)
            return 0;

        int windowSum = 0;
        int maxSum = INT_MIN;

        // calculate sum of first window
        for (int i = 0; i < k; i++)
        {
            windowSum += arr[i];
        }
        maxSum = windowSum;

        // slide the window
        for (int i = k; i < n; i++)
        {
            windowSum += arr[i] - arr[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};

int main()
{
    Solution sol;
    vector<int> arr1 = {100, 200, 300, 400};
    cout << sol.maxSubarraySum(arr1, 2) << endl; // Output: 700
    
    vector<int> arr2 = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    cout << sol.maxSubarraySum(arr2, 4) << endl; // Output: 39
    
    vector<int> arr3 = {100, 200, 300, 400};
    cout << sol.maxSubarraySum(arr3, 1) << endl; // Output: 400
    
    return 0;
}