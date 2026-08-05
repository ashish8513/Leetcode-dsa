//? Subarrays with Sum in Range

// Given an integer array arr[] and two integers l and r, find the number of subarrays whose sum lies in the range [l, r] (inclusive).

// A subarray is a contiguous sequence of elements within the array.

class Solution {
public:
    int countAtMost(vector<int>& arr, int k) {
        if (k < 0) return 0;

        int left = 0;
        int sum = 0;
        int cnt = 0;

        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];

            while (sum > k) {
                sum -= arr[left];
                left++;
            }

            cnt += (right - left + 1);
        }

        return cnt;
    }

    int countSubarray(vector<int>& arr, int l, int r) {
        return countAtMost(arr, r) - countAtMost(arr, l - 1);
    }
};