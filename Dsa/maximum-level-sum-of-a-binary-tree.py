# Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

# Return the smallest level x such that the sum of all the values of nodes at level x is maximal.


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        # I need to keep track of the current level in the local stack while recursing
        sums = {}
        self.calculateLevelSum(root, 1, sums)
        best_sum = float('-inf')
        best_level = 1

        # what if there are two levels with the same sum?
        # then return smallest level
        for k,v in sums.items():
            if v > best_sum:
                best_level = k
                best_sum = v
        return best_level

        
    def calculateLevelSum(self, root, level, sums):
        # if current level not computed, set the sum of the level as the current node's value
        if level not in sums.keys():
            sums[level] = 0
        
        sums[level] += root.val

        if root.left:
            self.calculateLevelSum(root.left, level + 1, sums)

        if root.right:
            self.calculateLevelSum(root.right, level + 1, sums)


