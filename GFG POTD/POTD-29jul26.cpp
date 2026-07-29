//? Split Array into Minimum Subsets

// Given an array arr[] of distinct positive numbers. Split the array into the minimum number of subsets (or subsequences) such that each subset contains consecutive numbers.


class Solution {
public:
    int minSubsets(vector<int>& arr) {
        if (arr.empty()) return 0;

        sort(arr.begin(), arr.end());

        int ans = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[i - 1] + 1)
                ans++;
        }

        return ans;
    }
};