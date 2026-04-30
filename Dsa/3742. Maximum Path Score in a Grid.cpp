// You are given an m x n grid where each cell contains one of the values 0, 1, or 2. You are also given an integer k.

// You start from the top-left corner (0, 0) and want to reach the bottom-right corner (m - 1, n - 1) by moving only right or down.

// Each cell contributes a specific score and incurs an associated cost, according to their cell values:

// 0: adds 0 to your score and costs 0.
// 1: adds 1 to your score and costs 1.
// 2: adds 2 to your score and costs 1. ​​​​​​​
// Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.

// Note: If you reach the last cell but the total cost exceeds k, the path is invalid.

 class Solution:
    def maxPathScore(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        
        t = [[[-1] * (k + 1) for _ in range(n)] for _ in range(m)]

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                is_pos = 1 if grid[i][j] > 0 else 0
                for cost in range(k + 1):
                    new_cost = cost + is_pos
                    if new_cost > k:
                        continue
                    if i == m - 1 and j == n - 1:
                        t[i][j][cost] = grid[i][j]
                        continue
                    else:
                        down = t[i + 1][j][new_cost] if i + 1 < m else -1
                        right = t[i][j + 1][new_cost] if j + 1 < n else -1
                        best_next = max(down, right)

                        if best_next != -1:
                            t[i][j][cost] = grid[i][j] + best_next
        
        return t[0][0][0]
