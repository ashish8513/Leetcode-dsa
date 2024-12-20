// Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

// For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
// Return the root of the reversed tree.

// A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

// The level of a node is the number of edges along the path between it and the root node.

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
var reverseOddLevels = function(root) {
    if (!root) return root;
    
    // Helper function to reverse values at each odd level
    const dfs = (leftNode, rightNode, level) => {
        // Base case: if we reach a null node, return
        if (!leftNode || !rightNode) return;
        
        // If the current level is odd, swap the values of the left and right nodes
        if (level % 2 === 1) {
            [leftNode.val, rightNode.val] = [rightNode.val, leftNode.val];
        }
        
        // Recurse for the children of the left and right nodes
        dfs(leftNode.left, rightNode.right, level + 1);
        dfs(leftNode.right, rightNode.left, level + 1);
    };
    
    // Start DFS from the children of the root (level 1)
    dfs(root.left, root.right, 1);
    
    return root;
};