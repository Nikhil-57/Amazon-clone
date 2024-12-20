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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr && root->val != val) {
            if (val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
};

int main() {
    // Creating a sample BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    
    Solution sol;
    TreeNode* result = sol.searchBST(root, 8);
    if (result) {
        cout << "Found node with value: " << result->val << endl;
    } else {
        cout << "Value not found in BST" << endl;
    }
    
    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
