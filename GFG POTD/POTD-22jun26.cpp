// // Maximum Area Between Bars
// Given an integer array height[], where height[i] represents the height of the ith bar arranged in a row, find the maximum rectangular area that can be formed by selecting any two bars. The area is calculated based on the original positions of the selected bars.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;

        while (left < right) {
            int width = right - left - 1;

            if (width > 0)
                ans = max(ans, min(height[left], height[right]) * width);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return ans;
    }
};