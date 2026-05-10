// Given an array of integers and a target value, return the indices of two numbers such that they add up to the target.
// Input:
// nums = [2,7,11,15]
// target = 9

// Output:
// [0,1]


#include <iostream>
using namespace std;

int main() {
    
    int nums[] = {2,7,11,15};
    int target = 9;
    int n = 4;

    for(int i = 0; i < n; i++) {
        
        for(int j = i + 1; j < n; j++) {
            
            if(nums[i] + nums[j] == target) {
                
                cout << i << " " << j;
            }
        }
    }

    return 0;
}