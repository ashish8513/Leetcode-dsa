// Given an array of integers and a number k, the task is the find maximum pair sum with the following conditions on the pairs.

// Pair difference should be less than k.
// Pairs should be disjoint. For example if (x, y) is a result pair, then neither x nor y should appear in any other result pair.
// Sum of p pairs means sum of 2p elements in the result.
// If no valid pairs can be formed, return 0.

// Examples:

class Solution {
public:
    long long sumDiffPairs(vector<int>& arr, int K) {
        sort(arr.begin(), arr.end());

        long long ans = 0;

        for(int i = arr.size() - 1; i > 0; ) {
            if(arr[i] - arr[i - 1] < K) {
                ans += arr[i] + arr[i - 1];
                i -= 2;
            } else {
                i--;
            }
        }

        return ans;
    }
}; 