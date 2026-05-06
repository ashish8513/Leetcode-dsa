// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
// Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

// Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.

// The tests are generated such that there is exactly one solution. You may not use the same element twice.

// Your solution must use only constant extra space.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right)
        {
            int sum = numbers[left] + numbers[right];

            if(sum == target)
            {
                return {left + 1, right + 1};
            }
            else if(sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return {};
    }
};
int main (){
    Solution obj;
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    vector<int> result = obj.twoSum(numbers, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}