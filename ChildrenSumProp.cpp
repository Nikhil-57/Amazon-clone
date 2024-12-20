#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            int min = q.front().second;  // to make the id starting from zero
            int first, last;
            for (int i = 0; i < size; i++) {
                long long cur_id = q.front().second - min;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) first = cur_id;
                if (i == size - 1) last = cur_id;
                if (node->left)
                    q.push({node->left, cur_id * 2 + 1});
                if (node->right)
                    q.push({node->right, cur_id * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};

int main() {
    // Create an example tree:
    //     1
    //    / \
    //   2   3
    //  / \   \
    // 4   5   7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution sol;
    int result = sol.widthOfBinaryTree(root);
    cout << "Maximum width of binary tree: " << result << endl;

    return 0;
}
