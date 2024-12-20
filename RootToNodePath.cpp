#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool getPath(TreeNode *root, vector<int> &arr, int x) {
        if (!root) return false;
        arr.push_back(root->val);

        if (root->val == x) return true;

        if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) {
            return true;
        }
        arr.pop_back();
        return false;
    }

    vector<int> solve(TreeNode *A, int B) {
        vector<int> arr;
        if (A == NULL) return arr;
        getPath(A, arr, B);
        return arr;
    }
};

int main() {
    // Creating an example tree:
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    //      \ 
    //       5 

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(5);

    Solution sol;
    int target = 5;
    vector<int> path = sol.solve(root, target);

    cout << "Path to " << target << ": ";
    for (int val : path) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
 