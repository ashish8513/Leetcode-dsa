// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &a)
    {

        int size = a.size();

        vector<int> neg;
        vector<int> pos;

        for (int i = 0; i < size; i++)
        {

            if (a[i] < 0)
                neg.push_back(a[i]);
            else
                pos.push_back(a[i]);
        }

        // Only positive numbers
        if (neg.size() == 0)
        {

            for (int i = 0; i < (int)pos.size(); i++)
                pos[i] = pos[i] * pos[i];

            return pos;
        }

        // Only negative numbers
        if (pos.size() == 0)
        {

            for (int i = 0; i < (int)neg.size(); i++)
                neg[i] = neg[i] * neg[i];

            reverse(neg.begin(), neg.end());

            return neg;
        }

        int i = 0, j = 0;
        int id = 0;

        int n = neg.size();
        int m = pos.size();

        vector<int> res(n + m);

        for (int i = 0; i < n; i++)
            neg[i] = neg[i] * neg[i];

        reverse(neg.begin(), neg.end());

        for (int i = 0; i < m; i++)
            pos[i] = pos[i] * pos[i];

        while (i < n && j < m)
        {

            if (neg[i] <= pos[j])
            {
                res[id++] = neg[i++];
            }
            else
            {
                res[id++] = pos[j++];
            }
        }

        while (i < n)
            res[id++] = neg[i++];

        while (j < m)
            res[id++] = pos[j++];

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sol.sortedSquares(nums);
    
    for (int num : result)
        cout << num << " ";
    cout << endl;
    
    return 0;
}