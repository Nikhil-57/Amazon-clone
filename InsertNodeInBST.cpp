#include <iostream>
#include <queue> // For level-order traversal
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val);

        TreeNode* cur = root;
        while (true) {
            if (cur->val < val) { // Changed <= to <
                if (cur->right != NULL) {
                    cur = cur->right;
                } else {
                    cur->right = new TreeNode(val);
                    break;
                }
            } else {
                if (cur->left != NULL) {
                    cur = cur->left;
                } else {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root; // Return the updated root of the tree
    }
};

// Helper function to print the tree in level-order for verification
void printLevelOrder(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";

        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
    cout << endl;
}

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(4);
    sol.insertIntoBST(root, 2);
    sol.insertIntoBST(root, 7);
    sol.insertIntoBST(root, 1);
    sol.insertIntoBST(root, 3);
    sol.insertIntoBST(root, 5);

    printLevelOrder(root); // Should print the tree in level-order
    return 0;
}
