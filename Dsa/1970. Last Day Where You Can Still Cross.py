
# There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

# Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

# You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

# Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

 

from collections import deque

class Solution:
    def latestDayToCross(self, row: int, col: int, cells: list[list[int]]) -> int:

        # Check if crossing is possible on 'day'
        def canCross(day):
            grid = [[0] * col for _ in range(row)]

            # Flood cells for the given day
            for i in range(day):
                r, c = cells[i]
                grid[r - 1][c - 1] = 1  # water

            q = deque()
            visited = [[False] * col for _ in range(row)]

            # Start from all land cells in top row
            for c in range(col):
                if grid[0][c] == 0:
                    q.append((0, c))
                    visited[0][c] = True

            directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

            while q:
                r, c = q.popleft()

                # Reached bottom row
                if r == row - 1:
                    return True

                for dr, dc in directions:
                    nr, nc = r + dr, c + dc
                    if (
                        0 <= nr < row and
                        0 <= nc < col and
                        not visited[nr][nc] and
                        grid[nr][nc] == 0
                    ):
                        visited[nr][nc] = True
                        q.append((nr, nc))

            return False

        # Binary Search
        left, right = 0, len(cells)
        answer = 0

        while left <= right:
            mid = (left + right) // 2
            if canCross(mid):
                answer = mid
                left = mid + 1
            else:
                right = mid - 1

        return answer
