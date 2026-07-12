//? 1331. Rank Transform of an Array
// Given an array of integers arr, replace each element with its rank.

// The rank represents how large the element is. The rank has the following rules:

// Rank is an integer starting from 1.
// The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
// Rank should be as small as possible.

#include <bits/stdc++.h>
using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> temp = arr;

    sort(temp.begin(), temp.end());

    unordered_map<int, int> rank;

    int r = 1;

    for (int num : temp) {
        if (rank.find(num) == rank.end()) {
            rank[num] = r++;
        }
    }

    vector<int> ans;

    for (int num : arr)
        ans.push_back(rank[num]);

    return ans;
}

int main() {
    vector<int> arr = {40,10,20,30};

    vector<int> ans = arrayRankTransform(arr);

    for (int x : ans)
        cout << x << " ";
}