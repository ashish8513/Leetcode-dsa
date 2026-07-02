//? Check Subset sum divisible by k
// Given an array arr[] of positive integers and a value k. Return true if the sum of any non-empty subset of the given array is divisible by k otherwise, return false.
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool divisibleByK(vector<int> &arr, int k)
    {

        vector<bool> dp(k, false);

        for (int x : arr)
        {
            vector<bool> next(dp);

            next[x % k] = true;

            for (int r = 0; r < k; r++)
            {
                if (dp[r])
                {
                    next[(r + x) % k] = true;
                }
            }

            if (next[0])
                return true;

            dp = next;
        }

        return false;
    }
};