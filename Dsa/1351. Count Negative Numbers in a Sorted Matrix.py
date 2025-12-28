# Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 class Solution:
    def countNegatives(self, grid: list[list[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        r = 0
        c = cols - 1
        count = 0

        while r < rows and c >= 0:
            if grid[r][c] < 0:
                count += (rows - r)
                c -= 1
            else:
                r += 1

        return count
