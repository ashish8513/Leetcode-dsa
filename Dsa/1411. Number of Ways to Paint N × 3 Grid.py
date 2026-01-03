# You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

# Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.




class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = 10**9 + 7
        
     
        abc = 6 
        aba = 6  
        
        for _ in range(2, n + 1):
            new_abc = (2 * abc + 2 * aba) % MOD
            new_aba = (2 * abc + 3 * aba) % MOD
            
            abc, aba = new_abc, new_aba
        
        return (abc + aba) % MOD
