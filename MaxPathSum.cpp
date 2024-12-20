#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathdown(root, maxi);
        return maxi;
    }

private:
    int maxPathdown(TreeNode* node, int& maxi) {
        if (node == NULL) return 0;

        int leftsum = max(0, maxPathdown(node->left, maxi));
        int rightsum = max(0, maxPathdown(node->right, maxi));

        maxi = max(maxi, leftsum + rightsum + node->val);
        return max(leftsum, rightsum) + node->val;
    }
};

int main() {
    // Creating a sample tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    int result = sol.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
