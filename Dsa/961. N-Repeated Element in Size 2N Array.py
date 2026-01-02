# You are given an integer array nums with the following properties:

# nums.length == 2 * n.
# nums contains n + 1 unique elements.
# Exactly one element of nums is repeated n times.
# Return the element that is repeated n times.

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        seen = set()
        for i in nums:
            if i in seen:
                return i
            else:
                seen.add(i)
