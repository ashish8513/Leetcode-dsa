// Given an integer n, your task is to compute the sum of all natural numbers from 1 to n (inclusive). If n is 0, the sum should be 0.


class Solution {
  public:
    int sumOfNaturals(int n) {
      if(n==0)
      return 0;
      int res=n*(n+1);
      int result=res/2;
      return result;
    }
};