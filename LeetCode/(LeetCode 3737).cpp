//? 3737. Count Subarrays With Majority Element I
// You are given an integer array nums and an integer target.

// Return the number of subarrays of nums in which target is the majority element.

// The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
    class Fenwick
    {
    public:
        vector<int> bit;
        int n;

        Fenwick(int sz)
        {
            n = sz;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val)
        {
            while (idx <= n)
            {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx)
        {
            int sum = 0;
            while (idx > 0)
            {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

public:
    int countMajoritySubarrays(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> vals = prefix;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick ft(vals.size());

        long long ans = 0;

        for (int x : prefix)
        {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;

            ans += ft.query(idx - 1);

            ft.update(idx, 1);
        }

        return (int)ans;
    }
};