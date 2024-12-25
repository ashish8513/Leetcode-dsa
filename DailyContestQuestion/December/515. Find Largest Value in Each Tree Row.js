// Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

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
 * @return {number[]}
 */
var largestValues = f = (node, l = 0, vals = []) => {
    if (node) {
        vals[l] = vals[l] > node.val ? vals[l] : node.val;
        f(node.left, l + 1, vals);
        f(node.right, l + 1, vals);
    }
    return vals;
};