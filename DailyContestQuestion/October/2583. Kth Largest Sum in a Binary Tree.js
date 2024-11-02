// You are given the root of a binary tree and a positive integer k.

// The level sum in the tree is the sum of the values of the nodes that are on the same level.

// Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.

// Note that two nodes are on the same level if they have the same distance from the root.

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
 * @param {number} k
 * @return {number}
 */
class TreeNode {
    constructor(val, left = null, right = null) {
      this.val = val;
      this.left = left;
      this.right = right;
    }
  }
  
  function kthLargestLevelSum(root, k) {
    if (!root) return -1; // Edge case: empty tree
  
    let levelSums = [];
    let queue = [root]; // Initialize the queue with the root node
  
    // BFS traversal
    while (queue.length > 0) {
      let levelSize = queue.length;
      let levelSum = 0;
  
      // Traverse all nodes at the current level
      for (let i = 0; i < levelSize; i++) {
        let currentNode = queue.shift(); // Get the current node
        levelSum += currentNode.val; // Add its value to the level sum
  
        // Add the left and right children of the current node to the queue
        if (currentNode.left) queue.push(currentNode.left);
        if (currentNode.right) queue.push(currentNode.right);
      }
  
      // Store the sum of the current level
      levelSums.push(levelSum);
    }
  
    // Sort the sums in descending order
    levelSums.sort((a, b) => b - a);
  
    // Return the k-th largest sum if it exists, otherwise return -1
    return levelSums.length >= k ? levelSums[k - 1] : -1;
  }
  
  // Example usage:
  let root = new TreeNode(1, 
    new TreeNode(2, new TreeNode(4), new TreeNode(5)), 
    new TreeNode(3, new TreeNode(6), new TreeNode(7))
  );
  
  console.log(kthLargestLevelSum(root, 2)); // Output: 12 (2nd largest sum is at level 1: 2 + 3 = 5)
  console.log(kthLargestLevelSum(root, 4)); // Output: -1 (There are only 3 levels)
  