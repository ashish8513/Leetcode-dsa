//? Mountain Subarray Queries

// Given an array arr[] and a list of queries. For each query [l, r], find whether the subarray arr[l...r] is a mountain array. A subarray is called a mountain array if there exists an index k (l ≤ k ≤ r) such that: arr[l] ≤ arr[l + 1] ≤ ... ≤ arr[k] ≥ arr[k + 1] ≥ ... ≥ arr[r].

// Elements of a Mountain subarray are first non-decreasing and then non-increasing.
// A subarray that is entirely non-decreasing or entirely non-increasing is also considered a mountain.

class Solution {
public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();

        vector<int> incEnd(n), decStart(n);

        // incEnd[i] = farthest index reachable by non-decreasing sequence
        incEnd[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1])
                incEnd[i] = incEnd[i + 1];
            else
                incEnd[i] = i;
        }

        // decStart[i] = leftmost index of non-increasing sequence ending at i
        decStart[0] = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] >= arr[i])
                decStart[i] = decStart[i - 1];
            else
                decStart[i] = i;
        }

        vector<bool> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            ans.push_back(decStart[r] <= incEnd[l]);
        }

        return ans;
    }
}; 