//? 3513. Number of Unique XOR Triplets I

// You are given an integer array nums of length n, where nums is a permutation of the numbers in the range [1, n].

// A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.

// Return the number of unique XOR triplet values from all possible triplets (i, j, k).
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return n;

        int bits = 0;
        while ((1 << bits) <= n) bits++;

        return 1 << bits;
    }
};