// Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

// Two nodes of a binary tree are cousins if they have the same depth with different parents.

// Return the root of the modified tree.

// Note that the depth of a node is the number of edges in the path from the root node to it.


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

let levelSums
let nodeValues
let parents
var replaceValueInTree = function(root) {
    levelSums = new Map()
    nodeValues = new Map()
    parents = new Map()
    
    dfs1(root, 0, null)
    console.log(levelSums)
    dfs2(root, 0, null)
    
    return root
    
};

function dfs1(node, level, parent){
    if(node == null){
        return
    }
    nodeValues.set(node, node.val)
    
    if(!levelSums.has(level)){
        levelSums.set(level, 0)
    }
    
    levelSums.set(level, node.val + levelSums.get(level))
    dfs1(node.left, level + 1, node)
    
    dfs1(node.right, level + 1, node)
    
    
}

function dfs2(node, level, parent){
    if(node == null){
        return
    }
    if(parent == null){
        node.val = 0;
       
    } else{

        let sum = levelSums.get(level);
        let left = parent.left
        let right = parent.right

        if(left){

            sum -= nodeValues.get(left)
        }
        if(right){
            sum -= nodeValues.get(right)
        }

        node.val = sum;
    }
    
    dfs2(node.left, level+1, node)
    dfs2(node.right, level+1, node)
}