# You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

# Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.

# Answers within 10-5 of the actual answer will be accepted.

# Note: Squares may overlap. Overlapping areas should be counted multiple times.

class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        total_area = 0
        diff = defaultdict(int)
        for _, y, l in squares:
            total_area += l * l
            diff[y] += l
            diff[y + l] -= l
        
        area = 0
        s = 0
        for y, y2 in pairwise(sorted(diff)):
            s += diff[y]
            area += s * (y2 - y)
            if area * 2 >= total_area:
                return y2 - (area * 2 - total_area) / (s * 2)