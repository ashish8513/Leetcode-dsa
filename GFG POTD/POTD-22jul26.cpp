//? Minimum Deletions to Make Sorted

// Given an array arr[], find the minimum number of elements to delete so that the remaining elements form a strictly increasing sequence in the same order.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(vector<int>& arr) {
        vector<int> lis;

        for (int x : arr) {
            auto it = lower_bound(lis.begin(), lis.end(), x);

            if (it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }

        return arr.size() - lis.size();
    }
};