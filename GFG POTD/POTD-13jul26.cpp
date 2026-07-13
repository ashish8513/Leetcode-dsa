//? Rearrange the Array

// Difficulty: HardAccuracy: 42.0%Submissions: 6K+Points: 8Average Time: 25m
// Consider an array a[] = [1, 2, 3, ..., n] and a permutation b[] of size n containing all integers from 1 to n exactly once.

// The array b[] defines a rearrangement operation.
// During a single operation, every element at position i in a[] moves to position b[i] (1-based indexing).
// We must do at least one operation on a[].
// Find the minimum number of operations required for all elements to return to their original positions simultaneously, i.e., for a[] to become: [1, 2, 3, ..., n] again.

// Note:  The answer can be large, so return the answer modulo 10^9+7.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int> &b) {
        int n = b.size();

        vector<int> original(n), curr(n), nxt(n);

        for (int i = 0; i < n; i++) {
            original[i] = i + 1;
            curr[i] = i + 1;
        }

        int operations = 0;

        do {
            
            for (int i = 0; i < n; i++) {
                nxt[b[i] - 1] = curr[i];
            }

            curr = nxt;
            operations++;

        } while (curr != original);

        return operations;
    }
};