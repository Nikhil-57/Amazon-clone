#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> preInPostTraversal(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        vector<int> pre, in, post;

        if (root == NULL) return {};

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            if (it.second == 1) {
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);
                if (it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            } else if (it.second == 2) {
                in.push_back(it.first->val);
                it.second++;
                st.push(it);
                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            } else {
                post.push_back(it.first->val);
            }
        }

        return {pre, in, post};
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.preInPostTraversal(root);

    cout << "Pre-order: ";
    for (int val : result[0]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "In-order: ";
    for (int val : result[1]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Post-order: ";
    for (int val : result[2]) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
