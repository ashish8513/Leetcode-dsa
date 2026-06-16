// There is an array that initially contains only a single value, 0. 

// Given a list of queries queries[][] of size q, where each query is of one of the following types:

// 0 x: Insert x into the array.
// 1 x: Replace every element a in the array with a ^ x, where ^ denotes the bitwise XOR operator.
// Return the array in sorted order after performing all the queries.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> constructList(vector<vector<int>>& queries) {
        vector<int> arr;
        arr.push_back(0);

        int xr = 0;

        for (auto &query : queries) {
            int type = query[0];
            int x = query[1];

            if (type == 0) {
                arr.push_back(x ^ xr);
            } else {
                xr ^= x;
            }
        }

        for (int &val : arr) {
            val ^= xr;
        }

        sort(arr.begin(), arr.end());
        return arr;
    }
};