#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});
    int max_depth = 0;

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int depth = q.front().second;
        q.pop();

        max_depth = std::max(max_depth, depth);

        if (node->left != NULL) {
            q.push({node->left, depth + 1});
        }
        if (node->right != NULL) {
            q.push({node->right, depth + 1});
        }
    }

    return max_depth;
}
