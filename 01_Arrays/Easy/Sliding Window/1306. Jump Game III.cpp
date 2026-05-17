// Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

// Notice that you can not jump outside of the array at any time.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    bool dfs(vector<int>& arr, int i, vector<int>& vis) {

        // out of bounds
        if(i < 0 || i >= arr.size())
            return false;

        // already visited
        if(vis[i])
            return false;

        // zero found
        if(arr[i] == 0)
            return true;

        // mark visited
        vis[i] = true;

        // forward jump
        bool forward = dfs(arr, i + arr[i], vis);

        // backward jump
        bool backward = dfs(arr, i - arr[i], vis);

        return forward || backward;
    }

    bool canReach(vector<int>& arr, int start) {

        vector<int> vis(arr.size(), 0);

        return dfs(arr, start, vis);
    }
};