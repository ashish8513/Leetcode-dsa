# You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

# Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.

# Answers within 10-5 of the actual answer will be accepted.

# Note: Squares may overlap. Overlapping areas should be counted only once in this version.


from typing import List

class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        events = []
        for x, y, l in squares:
            events.append((y, 1, x, x + l))
            events.append((y + l, -1, x, x + l))

        events.sort()

        def union(intervals):
            if not intervals:
                return 0.0
            intervals.sort()
            s, e = intervals[0]
            res = 0.0
            for a, b in intervals[1:]:
                if a > e:
                    res += e - s
                    s, e = a, b
                else:
                    e = max(e, b)
            return res + (e - s)

        active = []
        prev = events[0][0]
        total = 0.0
        strips = []

        for y, t, x1, x2 in events:
            if y > prev:
                w = union(active)
                strips.append((prev, y, w))
                total += w * (y - prev)
            if t == 1:
                active.append((x1, x2))
            else:
                active.remove((x1, x2))
            prev = y

        half = total / 2
        cur = 0.0

        for y1, y2, w in strips:
            area = w * (y2 - y1)
            if cur + area >= half:
                return y1 + (half - cur) / w
            cur += area

        return prev
