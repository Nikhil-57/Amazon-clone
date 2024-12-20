#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL) {
            return (p == q);
        }
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    // Creating two sample trees:
    // Tree 1:       1
    //              / \
    //             2   3
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    // Tree 2:       1
    //              / \
    //             2   3
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isSameTree(root1, root2);

    cout << (result ? "Trees are the same" : "Trees are not the same") << endl;

    // Clean up memory
    delete root1->left;
    delete root1->right;
    delete root1;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
