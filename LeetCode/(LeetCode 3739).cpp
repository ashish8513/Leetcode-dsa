// You are given an integer array nums and an integer target.

// Return the number of subarrays of nums in which target is the majority element.

// The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    class Fenwick {
    public:
        vector<int> bit;
        int n;

        Fenwick(int sz) {
            n = sz;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        Fenwick ft(2 * n + 5);
        int offset = n + 2;

        long long ans = 0;
        int prefix = 0;

        ft.update(offset, 1); // prefix sum = 0

        for (int x : nums) {
            if (x == target)
                prefix++;
            else
                prefix--;

            ans += ft.query(prefix + offset - 1);
            ft.update(prefix + offset, 1);
        }

        return ans;
    }
};