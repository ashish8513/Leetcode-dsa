//? Construct a Full Binary Tree


// Given two arrays pre[] and preMirror[] of size n containing unique elements, where pre[] represents the preorder traversal of a full binary tree and preMirror[] represents the preorder traversal of its mirror tree, construct the original full binary tree using these traversals.

// Note: A general binary tree cannot be uniquely constructed using these two traversals. However, a full binary tree can be constructed uniquely from the given traversals without any ambiguity.

/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
public:
    int preIndex = 0;
    unordered_map<int, int> pos;

    Node* build(vector<int>& pre, vector<int>& preMirror, int l, int h) {
        if (preIndex >= pre.size() || l > h)
            return nullptr;

        Node* root = new Node(pre[preIndex++]);

        if (l == h || preIndex >= pre.size())
            return root;

        int idx = pos[pre[preIndex]];

        if (idx <= h) {
            root->left = build(pre, preMirror, idx, h);
            root->right = build(pre, preMirror, l + 1, idx - 1);
        }

        return root;
    }

    Node* constructBinaryTree(vector<int>& pre, vector<int>& preMirror) {
        int n = pre.size();

        for (int i = 0; i < n; i++)
            pos[preMirror[i]] = i;

        preIndex = 0;
        return build(pre, preMirror, 0, n - 1);
    }
};