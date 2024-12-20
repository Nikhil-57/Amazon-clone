#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track, TreeNode* target) {
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            if (current->left) {
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;  // node -> parent
        markParents(root, parent_track, target);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;

        while (!queue.empty()) {
            int size = queue.size();
            if (curr_level++ == k) break;
            for (int i = 0; i < size; i++) {
                TreeNode* current = queue.front();
                queue.pop();
                if (current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if (current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }

        vector<int> result;
        while (!queue.empty()) {
            TreeNode* current = queue.front();
            queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};

int main() {
    // Create an example tree:
    //      3
    //     / \
    //    5   1
    //   / \ / \
    //  6  2 0  8
    //    / \
    //   7   4

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    int k = 2;
    TreeNode* target = root->left;  // Target node is 5
    vector<int> result = sol.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target node " << target->val << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
