#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int tar = 9;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == tar)
            {
                cout << nums[i] << " " << nums[j] << endl;
                return 0;
            }
        }
    }   
}