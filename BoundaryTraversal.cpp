#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
    bool isLeaf(Node* node) {
        return !node->left && !node->right;
    }

    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) res.push_back(cur->data);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }

    void addRightBoundary(Node* root, vector<int>& res) {
        Node* cur = root->right;
        vector<int> tmp;
        while (cur) {
            if (!isLeaf(cur)) tmp.push_back(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for (int i = tmp.size() - 1; i >= 0; --i) {
            res.push_back(tmp[i]);
        }
    }

    void addLeaves(Node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }

public:
    vector<int> printBoundary(Node* root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};

int main() {
    // Example usage:
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.printBoundary(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (not strictly necessary in short-lived programs)
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
