// Longest Consecutive Path in Binary tree

// Given the root of a Binary Tree, find the length of the longest path consisting of connected nodes such that each next node has a value exactly 1 greater than its parent.

// The path must move from parent to child only and follow increasing consecutive values.

// If no such path exists, return -1.

/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
public:
    int ans = 1;

    void dfs(Node* root, int prev, int len) {
        if (!root) return;

        if (root->data == prev + 1)
            len++;
        else
            len = 1;

        ans = max(ans, len);

        dfs(root->left, root->data, len);
        dfs(root->right, root->data, len);
    }

    int longestConsecutive(Node* root) {
        if (!root) return -1;

        dfs(root, root->data - 1, 0);

        return (ans == 1) ? -1 : ans;
    }
};