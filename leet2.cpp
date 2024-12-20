#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct SubtreeInfo {
    bool isPerfect;
    int height;
    int size;
};

SubtreeInfo findPerfectSubtree(TreeNode* node, vector<int>& sizes) {
    if (!node) return {true, 0, 0};
    
    SubtreeInfo left = findPerfectSubtree(node->left, sizes);
    SubtreeInfo right = findPerfectSubtree(node->right, sizes);
    
    if (left.isPerfect && right.isPerfect && left.height == right.height) {
        int currentSize = left.size + right.size + 1;
        sizes.push_back(currentSize);
        return {true, left.height + 1, currentSize};
    }
    
    return {false, 0, 0};
}

int kthLargestPerfectSubtree(TreeNode* root, int k) {
    vector<int> sizes;
    findPerfectSubtree(root, sizes);
    
    if (sizes.size() < k) return -1;
    
    sort(sizes.begin(), sizes.end(), greater<int>());
    
    return sizes[k - 1];
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(8);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(8);

    int k = 2;
    cout << "The size of the " << k << "-th largest perfect binary subtree is: "
         << kthLargestPerfectSubtree(root, k) << endl;

    return 0;
}
