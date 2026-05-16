// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

// [4,5,6,7,0,1,4] if it was rotated 4 times.
// [0,1,4,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

// You must decrease the overall operation steps as much as possible.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {

            int mid = low + (high - low) / 2;

            // minimum right side mein
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }

            // minimum left side mein
            else if (nums[mid] < nums[high]) {
                high = mid;
            }

            // duplicates
            else {
                high--;
            }
        }

        return nums[low];
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << sol.findMin(nums1) << endl; // Output: 1
    
    vector<int> nums2 = {2, 1};
    cout << sol.findMin(nums2) << endl; // Output: 1
    
    vector<int> nums3 = {1, 3};
    cout << sol.findMin(nums3) << endl; // Output: 1
    
    return 0;
}