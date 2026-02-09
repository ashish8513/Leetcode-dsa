# Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

# A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
   
        inorder_vals = []
        
        def inorder(node):
            if not node:
                return
            inorder(node.left)
            inorder_vals.append(node.val)
            inorder(node.right)
        
        inorder(root)
        
        def build(l, r):
            if l > r:
                return None
            mid = (l + r) // 2
            node = TreeNode(inorder_vals[mid])
            node.left = build(l, mid - 1)
            node.right = build(mid + 1, r)
            return node
        
        return build(0, len(inorder_vals) - 1)
