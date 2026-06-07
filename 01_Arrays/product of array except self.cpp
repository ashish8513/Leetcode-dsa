#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<int>productExceptSelf(vector<int>&nums){
        for(int i=0;i<nums;i++){
            prod=1;
            for(int j=0;j<nums;j++){
                if(i!=j){
                    prod *=nums[j];
                }
                ans[i]=prod;
            }
        }
    }
}