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
    int FloorInBST(TreeNode* root, int key) {
        int floor = -1;
        while (root) {
            if (root->val == key) {
                floor = root->val;
                return floor;
            }
            if (key > root->val) {
                floor = root->val;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return floor;
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
    int result = sol.FloorInBST(root, key);
    if (result != -1) {
        cout << "Floor value of " << key << " in BST is: " << result << endl;
    } else {
        cout << "No floor value found for " << key << " in BST" << endl;
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
