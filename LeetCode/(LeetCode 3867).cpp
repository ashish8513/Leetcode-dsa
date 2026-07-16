//? 3867. Sum of GCD of Formed Pairs

// You are given an integer array nums of length n.

// Construct an array prefixGcd where for each index i:

// Let mxi = max(nums[0], nums[1], ..., nums[i]).
// prefixGcd[i] = gcd(nums[i], mxi).
// After constructing prefixGcd:

// Sort prefixGcd in non-decreasing order.
// Form pairs by taking the smallest unpaired element and the largest unpaired element.
// Repeat this process until no more pairs can be formed.
// For each formed pair, compute the gcd of the two elements.
// If n is odd, the middle element in the prefixGcd array remains unpaired and should be ignored.
// Return an integer denoting the sum of the GCD values of all formed pairs.

// The term gcd(a, b) denotes the greatest common divisor of a and b.


class Solution {
public:
    long long sumOfGcdPairs(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixGcd(n);

        int mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(nums[i], mx);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        int i = 0, j = n - 1;
        while (i < j) {
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return ans;
    }
};