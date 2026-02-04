# You are given an integer array nums of length n.

# A trionic subarray is a contiguous subarray nums[l...r] (with 0 <= l < r < n) for which there exist indices l < p < q < r such that:

# nums[l...p] is strictly increasing,
# nums[p...q] is strictly decreasing,
# nums[q...r] is strictly increasing.
# Return the maximum sum of any trionic subarray in nums.
class Solution:
    def maxTrionicSum(self, nums: list[int]) -> int:
        n = len(nums)
        if n < 4:
            return 0

        # Prefix sum
        prefix = [0] * n
        prefix[0] = nums[0]
        for i in range(1, n):
            prefix[i] = prefix[i - 1] + nums[i]

        # incL[i] = start index of increasing subarray ending at i
        incL = list(range(n))
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                incL[i] = incL[i - 1]

        # incR[i] = end index of increasing subarray starting at i
        incR = list(range(n))
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                incR[i] = incR[i + 1]

        ans = 0
        i = 1

        while i < n - 1:
            # Find decreasing part
            if nums[i] > nums[i + 1]:
                p = i
                while i + 1 < n and nums[i] > nums[i + 1]:
                    i += 1
                q = i

                # Validate trionic shape
                if p - 1 >= 0 and q + 1 < n:
                    l = incL[p - 1]
                    r = incR[q + 1]

                    if l < p and q < r:
                        curr_sum = prefix[r] - (prefix[l - 1] if l > 0 else 0)
                        ans = max(ans, curr_sum)
            i += 1

        return ans
