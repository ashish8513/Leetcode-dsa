// Given a bag of size w kg and you are provided costs of packets different weights of oranges in array cost[], find the minimum total cost to buy exactly w kg oranges

// The cost of 1 kg orange is present at index 0 and in general arr[i] has cost of (i+1) kg orange.
// cost[i] = -1 means that 'i+1' kg packet of orange is unavailable.
// If it is not possible to buy exactly w kg oranges then return -1. It may be assumed that there is an infinite supply of all available packet types.
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumCost(vector<int>& cost, int w) {
        const int INF = 1e9;

        vector<int> dp(w + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < cost.size(); i++) {
            if (cost[i] == -1) continue;

            int wt = i + 1;

            for (int j = wt; j <= w; j++) {
                dp[j] = min(dp[j], dp[j - wt] + cost[i]);
            }
        }

        return (dp[w] == INF) ? -1 : dp[w];
    }
}; 