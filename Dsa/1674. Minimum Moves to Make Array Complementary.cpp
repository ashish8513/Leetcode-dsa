// You are given an integer array nums of even length n and an integer limit. In one move, you can replace any integer from nums with another integer between 1 and limit, inclusive.

// The array nums is complementary if for all indices i (0-indexed), nums[i] + nums[n - 1 - i] equals the same number. For example, the array [1,2,3,4] is complementary because for all indices i, nums[i] + nums[n - 1 - i] = 5.

// Return the minimum number of moves required to make nums complementary.


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int minMoves(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for(int i = 0; i < n / 2; i++) {

            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = 1 + min(a, b);

            int high = limit + max(a, b);

            int sum = a + b;

            // Initially 2 moves
            diff[2] += 2;

            // One move range starts
            diff[low] -= 1;

            // Zero move at exact sum
            diff[sum] -= 1;

            diff[sum + 1] += 1;

            // Back to 2 moves
            diff[high + 1] += 1;
        }

        int ans = INT_MAX;

        int curr = 0;

        for(int s = 2; s <= 2 * limit; s++) {

            curr += diff[s];

            ans = min(ans, curr);
        }

        return ans;
    }
};
