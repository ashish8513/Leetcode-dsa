//? 3514. Number of Unique XOR Triplets II

// You are given an integer array nums.

// A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.

// Return the number of unique XOR triplet values from all possible triplets (i, j, k).

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 1;

        unordered_set<int> pairXor;
        unordered_set<int> ans;

        // XOR of every pair (i < j)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }

        // pair XOR with every element
        for (int px : pairXor) {
            for (int x : nums) {
                ans.insert(px ^ x);
            }
        }

        return ans.size();
    }
}; 