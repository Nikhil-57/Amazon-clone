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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // Outer map maps the x-coordinate to a map
        //Inner map maps the y-coordinate to a multiset that contains all node values at that specific position.
        //Multiset is used to store the node values because it automatically sorts the values, 
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;

            nodes[x][y].insert(node->val);
            if (node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};

int main() {
    // Creating an example tree:
    //       3
    //      / \
    //     9   20
    //        /  \
    //       15   7

    // TreeNode* root = new TreeNode(3);
    // root->left = new TreeNode(9);
    // root->right = new TreeNode(20);
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);

    Solution solution;
    vector<vector<int>> result = solution.verticalTraversal(root);

    // Printing the result
    for (const auto& vec : result) {
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    // Clean up memory (optional, as the program will end here)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
