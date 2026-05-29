// You are given an integer array nums. We consider an array good if it is a permutation of an array base[n].

// base[n] = [1, 2, ..., n - 1, n, n] (in other words, it is an array of length n + 1 which contains 1 to n - 1 exactly once, plus two occurrences of n). For example, base[1] = [1, 1] and base[3] = [1, 2, 3, 3].

// Return true if the given array is good, otherwise return false.

// Note: A permutation of integers represents an arrangement of these numbers.

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());

        if (nums.size() != n + 1)
            return false;

        vector<int> freq(n + 1, 0);

        for (int x : nums) {
            if (x < 1 || x > n)
                return false;
            freq[x]++;
        }

        if (freq[n] != 2)
            return false;

        for (int i = 1; i < n; i++) {
            if (freq[i] != 1)
                return false;
        }

        return true;
    }
}; 