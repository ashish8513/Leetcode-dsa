// You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

// Every element less than pivot appears before every element greater than pivot.
// Every element equal to pivot appears in between the elements less than and greater than pivot.
// The relative order of the elements less than pivot and the elements greater than pivot is maintained.
// More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. If i < j and both elements are smaller (or larger) than pivot, then pi < pj.
// Return nums after the rearrangement.

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;

        for (int x : nums) {
            if (x < pivot)
                less.push_back(x);
            else if (x == pivot)
                equal.push_back(x);
            else
                greater.push_back(x);
        }

        vector<int> ans;

        for (int x : less) ans.push_back(x);
        for (int x : equal) ans.push_back(x);
        for (int x : greater) ans.push_back(x);

        return ans;
    }
};