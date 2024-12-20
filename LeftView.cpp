#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }

private:
    void recursion(TreeNode *root, int level, vector<int> &res) {
        if (root == NULL) return;

        if (res.size() == level) {
            res.push_back(root->val);
        }
        recursion(root->left, level + 1, res);
        recursion(root->right, level + 1, res);
    }
};

int main() {
    // Creating an example tree:
    //   3
    //  / \
    // 9   20
    //    /  \
    //   15   7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
