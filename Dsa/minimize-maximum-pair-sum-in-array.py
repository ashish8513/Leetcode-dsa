# The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.

# For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
# Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:

# Each element of nums is in exactly one pair, and
# The maximum pair sum is minimized.
# Return the minimized maximum pair sum after optimally pairing up the elements.
class Solution:
    def minPairSum(self, nums):
        nums.sort()
        
        left = 0
        right = len(nums) - 1
        max_sum = 0
        
        while left < right:
            pair_sum = nums[left] + nums[right]
            max_sum = max(max_sum, pair_sum)
            left += 1
            right -= 1
        
        return max_sum