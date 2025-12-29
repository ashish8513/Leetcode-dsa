# You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.

# To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.

# For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
# You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.

# Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.


from collections import defaultdict

class Solution:
    def pyramidTransition(self, bottom: str, allowed: list[str]) -> bool:
        
        mp = defaultdict(list)
        for a in allowed:
            mp[a[:2]].append(a[2])

        def build(row):
            if len(row) == 1:
                return True

            def dfs(i, next_row):
                if i == len(row) - 1:
                    return build(next_row)

                pair = row[i:i+2]
                if pair not in mp:
                    return False

                for ch in mp[pair]:
                    if dfs(i + 1, next_row + ch):
                        return True
                return False

            return dfs(0, "")

        return build(bottom)
