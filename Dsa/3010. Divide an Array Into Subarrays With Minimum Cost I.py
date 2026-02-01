# You are given an array of integers nums of length n.

# The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.

# You need to divide nums into 3 disjoint contiguous subarrays.

# Return the minimum possible sum of the cost of these subarrays.

 class Solution:
    def minimumCost(self, nums: List[int]) -> int:

        min_cost = float("inf")
        for i in range(1, len(nums)):
            for j in range(i+1, len(nums)):
                min_cost = min(min_cost, nums[0] + nums[i] + nums[j])
    
        return min_cost
