# You are given an integer array nums.

# A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.

# Return the length of the longest balanced subarray.

class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0

        for i in range(n):
            odd = set()
            even = set()

            for j in range(i, n):
                if nums[j] % 2 == 0:
                    even.add(nums[j])
                else:
                    odd.add(nums[j])

                if len(odd) == len(even):
                    ans = max(ans, j - i + 1)

        return ans
