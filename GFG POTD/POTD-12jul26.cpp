// Max Amount by Selling K Tickets

// Given an integer array arr[], where arr[i] denotes the number of tickets available with the i-th ticket seller.

// The price of each ticket is equal to the number of tickets remaining with that seller at the time of sale. 
// A seller can sell at most one ticket at a time, and after each sale, the price of the next ticket from that seller decreases by 1.
// All sellers are allowed to sell at most k tickets in total.
// Find the maximum amount that can be earned by selling k tickets. Return the answer modulo 109+7.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxAmount(vector<int>& arr, int k) {

        const int MOD = 1e9 + 7;

        priority_queue<int> pq;

        for (int x : arr)
            pq.push(x);

        long long ans = 0;

        while (k-- && !pq.empty()) {

            int curr = pq.top();
            pq.pop();

            ans = (ans + curr) % MOD;

            curr--;

            if (curr > 0)
                pq.push(curr);
        }

        return ans % MOD;
    }
};