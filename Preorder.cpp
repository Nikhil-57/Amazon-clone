#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform preorder traversal.
void preorder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    // Print the current node's value.
    cout << node->val << " ";
    // Traverse the left subtree.
    preorder(node->left);
    // Traverse the right subtree.
    preorder(node->right);
}

int main() {
    // Creating a simple binary tree for testing.
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Perform preorder traversal.
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    // Clean up dynamically allocated memory (optional but good practice).
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
