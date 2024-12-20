#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class solution{
    public:
        int MaxDepth(TreeNode* root){
            if(root == NULL) return 0;
            int left = MaxDepth(root->left);
            int right = MaxDepth(root->right);
            return 1 + max(left, right);
        }
};