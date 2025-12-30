# A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

# Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?

# Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

class Solution:
    def numMagicSquaresInside(self, grid):
        m, n = len(grid), len(grid[0])
        ans = 0

        for i in range(m - 2):
            for j in range(n - 2):

         
                vals = [
                    grid[i][j], grid[i][j+1], grid[i][j+2],
                    grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2],
                    grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2]
                ]

                if sorted(vals) != [1,2,3,4,5,6,7,8,9]:
                    continue

             
                if grid[i][j] + grid[i][j+1] + grid[i][j+2] != 15:
                    continue
                if grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] != 15:
                    continue
                if grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2] != 15:
                    continue

              
                if grid[i][j] + grid[i+1][j] + grid[i+2][j] != 15:
                    continue
                if grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] != 15:
                    continue
                if grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] != 15:
                    continue

             
                if grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != 15:
                    continue
                if grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != 15:
                    continue

                ans += 1

        return ans
 
