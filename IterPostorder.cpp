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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (root == NULL) return postorder;

        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* temp;

        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                temp = st.top()->right;
                if (temp == NULL) {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                } else {
                    curr = temp;
                }
            }
        }

        return postorder;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.postorderTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
