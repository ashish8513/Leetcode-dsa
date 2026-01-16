# There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1) and (m, n) containing some horizontal and vertical fences given in arrays hFences and vFences respectively.

# Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i], n) and vertical fences are from the coordinates (1, vFences[i]) to (m, vFences[i]).

# Return the maximum area of a square field that can be formed by removing some fences (possibly none) or -1 if it is impossible to make a square field.

# Since the answer may be large, return it modulo 109 + 7.

# Note: The field is surrounded by two horizontal fences from the coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be removed.


class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: List[int],
                                 vFences: List[int]) -> int:

        deltas, mxDelta = set(), 0
        hFences = sorted(chain(hFences, [1, m]))
        vFences = sorted(chain(vFences, [1, n]))

        for i, top in enumerate(hFences):
            for bot in hFences[i+1:]:
                deltas.add(bot - top)
    
        for i, lft in enumerate(vFences):
            for rgt in vFences[i+1:][::-1]:   #  <-- * 
                delta = rgt - lft
                if delta <= mxDelta or delta not in deltas: continue
                mxDelta = delta
                break

        if mxDelta == 0: return -1
        return pow(mxDelta, 2, 1_000_000_007)