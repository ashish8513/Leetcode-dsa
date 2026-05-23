// Given an array integer arr[] , representing the values of coins arranged in a row.

// Two players play a game by picking coins alternately.
// At each turn, a player can pick a coin from either the beginning or the end of the array. Both players follow a greedy strategy, i.e., they always pick the coin with the maximum value among the two available ends.
// The game continues until only one coin remains.
// Find the value of the last remaining coin.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
       int i =0 ;
       int j= arr.size()-1;
       while(i<j){
           if(arr[i]>arr[j]){
               i++;
           }else{
               j--;
           }
       }
       return arr[i];
    }
};