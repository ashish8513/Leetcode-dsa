# You are given the two integers, n and m and two integer arrays, hBars and vBars. The grid has n + 2 horizontal and m + 2 vertical bars, creating 1 x 1 unit cells. The bars are indexed starting from 1.

# You can remove some of the bars in hBars from horizontal bars and some of the bars in vBars from vertical bars. Note that other bars are fixed and cannot be removed.

# Return an integer denoting the maximum area of a square-shaped hole in the grid, after removing some bars (possibly none).

class Solution:
    def maximizeSquareHoleArea(self, n, m, hBars, vBars):

        def longest_consecutive(arr):
            arr.sort()
            max_len = 0
            curr_len = 0
            prev = None
            
            for x in arr:
                if prev is None or x != prev + 1:
                    curr_len = 1
                else:
                    curr_len += 1
                
                max_len = max(max_len, curr_len)
                prev = x
            
            return max_len

        max_h = longest_consecutive(hBars)
        max_v = longest_consecutive(vBars)

        side = min(max_h + 1, max_v + 1)
        return side * side
