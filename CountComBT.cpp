#include <iostream> // For standard I/O operations

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if (lh == rh) return (1 << lh) - 1;// (1 << lh) can also be written like pow(2, lh) but use cmath library

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int findHeightLeft(TreeNode* node) {
        int hght = 0;
        while (node) {
            hght++;
            node = node->left;
        }
        return hght;
    }

    int findHeightRight(TreeNode* node) {
        int hght = 0;
        while (node) {
            hght++;
            node = node->right;
        }
        return hght;
    }
};

// Utility function to create a new tree node
TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode(data);
    node->left = node->right = NULL;
    return node;
}

// Example usage
int main() {
    // Creating a simple complete binary tree for demonstration
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    Solution sol;
    std::cout << "Total nodes: " << sol.countNodes(root) << std::endl; // Output should be 6

    return 0;
}
