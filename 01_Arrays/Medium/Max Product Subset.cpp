// Given an array arr[], find and return the maximum product possible with the subset of elements present in the array.

// Note:

// The maximum product can be of a single element also.
// Since the product can be large, return it modulo 109 + 7.

class Solution {
public:
    long long findMaxProduct(vector<int>& arr) {
        const long long MOD = 1000000007;

        int n = arr.size();

        if (n == 1)
            return arr[0];

        int negCount = 0, zeroCount = 0;
        int maxNeg = INT_MIN;

        long long prod = 1;

        for (int x : arr) {
            if (x == 0) {
                zeroCount++;
                continue;
            }

            if (x < 0) {
                negCount++;
                maxNeg = max(maxNeg, x);
            }
        }

        // all zeros
        if (zeroCount == n)
            return 0;

        // only one negative and rest zeros
        if (negCount == 1 && zeroCount + negCount == n)
            return 0;

        bool skipped = false;

        for (int x : arr) {
            if (x == 0)
                continue;

            if (negCount % 2 && x == maxNeg && !skipped) {
                skipped = true;
                continue;
            }

            prod = (prod * ((x % MOD + MOD) % MOD)) % MOD;
        }

        return prod;
    }
}; 