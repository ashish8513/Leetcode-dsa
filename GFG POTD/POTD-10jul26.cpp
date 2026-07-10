//? Ways to Express as Sum of Consecutives
// Given a number n, find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int getCount(int n) {
     while (n % 2 == 0)
            n /= 2;

        int ans = 1;

        for (int i = 3; i * i <= n; i += 2) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            ans *= (cnt + 1);
        }

        if (n > 1)
            ans *= 2;

        return ans - 1;
    }
};