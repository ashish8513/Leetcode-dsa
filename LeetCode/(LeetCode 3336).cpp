//? 3336. Find the Number of Subsequences With Equal GCD

// You are given an integer array nums.

// Your task is to find the number of pairs of non-empty subsequences (seq1, seq2) of nums that satisfy the following conditions:

// The subsequences seq1 and seq2 are disjoint, meaning no index of nums is common between them.
// The GCD of the elements of seq1 is equal to the GCD of the elements of seq2.
// Return the total number of such pairs.

// Since the answer may be very large, return it modulo 109 + 7.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int mod=1e9+7;
  
    int solve(int i,int s1,int s2,vector<int> &nums,vector<vector<vector<int>>> &dp){
        if(i>=nums.size()){
            if(s1!=0 && s2!=0 && s1==s2){
                return 1;
            }
            return 0;
        }
        if(dp[i][s1][s2]!=-1){
            return dp[i][s1][s2];
        }
        int c=solve(i+1,s1,s2,nums,dp);
        int a=solve(i+1,__gcd(s1,nums[i]),s2,nums,dp);
        int b=solve(i+1,s1,__gcd(s2,nums[i]),nums,dp);

        return dp[i][s1][s2]=((a+b)%mod+c)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
         int n=nums.size();
         int maxi=*max_element(nums.begin(),nums.end());
         vector<vector<vector<int>>> dp(n,vector<vector<int>>(maxi+1,vector<int>(maxi+1,-1)));
         return solve(0,0,0,nums,dp);
    }
};