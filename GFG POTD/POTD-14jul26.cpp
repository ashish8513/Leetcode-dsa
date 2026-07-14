//? Smallest Non-Zero Number

// Given an array arr[], find the smallest number x such that when x is processed sequentially with each element of the array (from index 0 to n-1), it never becomes negative, under the following conditions:

// If x is greater than the current array element, x is increased by the difference between x and the array element.
// If x is less than or equal to the current array element, x is decreased by the difference between the array element and x.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int find(vector<int> &arr) {
        long long x = 0;

        for (int i = arr.size() - 1; i >= 0; i--) {
            x = (x + arr[i] + 1) / 2;   // ceil((x + arr[i]) / 2)
        }

        return (int)x;
    }
};
