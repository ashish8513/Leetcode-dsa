// Given a root of a binary tree with n nodes, where each node may contain positive or negative values, convert it into a tree such that each node’s new value is equal to the sum of all values in its left and right subtrees(based on the original tree).For leaf nodes, update their values to 0.
#include <iostream>
#include <bits/stdc++.h>

class Solution {
public:
    
    int solve(Node* root) {
        // base case
        if(root == NULL) return 0;
        
        // leaf node
        if(root->left == NULL && root->right == NULL) {
            int temp = root->data;
            root->data = 0;
            return temp;
        }
        
        // left subtree sum
        int leftSum = solve(root->left);
        
        // right subtree sum
        int rightSum = solve(root->right);
        
        int oldValue = root->data;
        
        // update current node
        root->data = leftSum + rightSum;
        
        // return total sum of subtree
        return oldValue + root->data;
    }
    
    void toSumTree(Node *node)
    {
        solve(node);
    }
};