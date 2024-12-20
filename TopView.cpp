#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left, * right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
public:
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;

            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }

            if (node->left != NULL) {
                q.push({node->left, line - 1});
            }
            if (node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main(){
      // Creating an example tree:
    //   3
    //  / \
    // 9   20
    //    /  \
    //   15   7

    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.topView(root);

    for (int i : result) {
        cout << i << " ";
    }

    // Free the allocated memory (optional but good practice)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;

}