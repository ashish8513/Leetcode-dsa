# You are given an array happiness of length n, and a positive integer k.

# There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.

# In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

# Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children


from typing import List

class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        
        total = 0
        
        for i in range(k):
            current = happiness[i] - i
            
            if current > 0:
                total += current
            else:
                break
        
        return total
