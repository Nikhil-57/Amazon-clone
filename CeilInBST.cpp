#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int CeilBST(TreeNode* root, int key) {
        int ceil = -1;
        while (root) {
            if (root->val == key) {
                ceil = root->val;
                return ceil;
            }
            if (key > root->val) {
                root = root->right;
            } else {
                ceil = root->val;
                root = root->left;
            }
        }
        return ceil;
    }
};

int main() {
    // Creating a sample BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    
    Solution sol;
    int key = 6;
    int result = sol.CeilBST(root, key);
    if (result != -1) {
        cout << "Ceiling value of " << key << " in BST is: " << result << endl;
    } else {
        cout << "No ceiling value found for " << key << " in BST" << endl;
    }
    
    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
