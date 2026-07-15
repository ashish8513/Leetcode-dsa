#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int main()
{
    vector<int> nums = {1, 2, 3, 2, 4};
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                cout << "Duplicate found: " << nums[i] << endl;
                return 0;
            }
            cout << nums[i] << " " << nums[j] << endl;
        }
    }
}