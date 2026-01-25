# There exist n rectangles in a 2D plane with edges parallel to the x and y axis. You are given two 2D integer arrays bottomLeft and topRight where bottomLeft[i] = [a_i, b_i] and topRight[i] = [c_i, d_i] represent the bottom-left and top-right coordinates of the ith rectangle, respectively.

# You need to find the maximum area of a square that can fit inside the intersecting region of at least two rectangles. Return 0 if such a square does not exist.

from typing import List

class Solution:
    def largestSquareArea(
        self,
        bottomLeft: List[List[int]],
        topRight: List[List[int]]
    ) -> int:
        n = len(bottomLeft)
        max_area = 0

        for i in range(n):
            x1, y1 = bottomLeft[i]
            x2, y2 = topRight[i]

            for j in range(i + 1, n):
                x3, y3 = bottomLeft[j]
                x4, y4 = topRight[j]

                left = max(x1, x3)
                bottom = max(y1, y3)
                right = min(x2, x4)
                top = min(y2, y4)

                if right > left and top > bottom:
                    side = min(right - left, top - bottom)
                    max_area = max(max_area, side * side)

        return max_area
