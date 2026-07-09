//? Count Pairs Divisible By K
// Given an array arr[] and positive integer k, count total number of pairs in the array whose sum is divisible by k.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countKdivPairs(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        int count = 0;

        for (int num : arr) {
            int rem = num % k;
            if (rem < 0) rem += k;  

            int need = (k - rem) % k;
            count += freq[need];
            freq[rem]++;
        }

        return count;
    }
};