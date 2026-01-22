# Given an array nums, you can perform the following operation any number of times:

# Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
# Replace the pair with their sum.
# Return the minimum number of operations needed to make the array non-decreasing.

# An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 from typing import List
import heapq

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1:
            return 0

        
        left = list(range(-1, n))
        right = list(range(1, n + 1))
        right[n - 1] = -1
        alive = [True] * n

  
        heap = []
        for i in range(n - 1):
            heapq.heappush(heap, (nums[i] + nums[i + 1], i))

        def is_non_decreasing():
            i = 0
            while right[i] != -1:
                if nums[i] > nums[right[i]]:
                    return False
                i = right[i]
            return True

        operations = 0

        while not is_non_decreasing():
         
            while True:
                pair_sum, i = heapq.heappop(heap)
                j = right[i]
                if j != -1 and alive[i] and alive[j] and nums[i] + nums[j] == pair_sum:
                    break

           
            nums[i] += nums[j]
            alive[j] = False
            operations += 1

          
            rj = right[j]
            right[i] = rj
            if rj != -1:
                left[rj] = i

            
            if left[i] != -1:
                li = left[i]
                heapq.heappush(heap, (nums[li] + nums[i], li))
            if right[i] != -1:
                ri = right[i]
                heapq.heappush(heap, (nums[i] + nums[ri], i))

        return operations
