#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // If the root is NULL, the tree is symmetric
        if (root == NULL) {
            return true;
        }
        // Check symmetry between the left and right subtrees
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode *left, TreeNode *right) {
        // If both nodes are NULL, they are symmetric
        if (left == NULL && right == NULL) {
            return true;
        }
        // If only one of the nodes is NULL, they are not symmetric
        if (left == NULL || right == NULL) {
            return false;
        }
        // Check if the current nodes have the same value and their subtrees are mirrors
        return (left->val == right->val) && 
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
};

int main() {
    // Create an example tree:
    //     1
    //    / \
    //   2   2
    //  / \ / \
    // 3  4 4  3

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isSymmetric(root);

    cout << (result ? "The tree is symmetric" : "The tree is not symmetric") << endl;

    return 0;
}
