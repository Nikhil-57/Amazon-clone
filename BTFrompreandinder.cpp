#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& prorder, vector<int>& inord) {
        unordered_map<int, int> inMap;

        for (int i = 0; i < inord.size(); i++) {
            inMap[inord[i]] = i;
        }

        return buildTree(prorder, 0, prorder.size() - 1,
                         inord, 0, inord.size() - 1, inMap);
    }

    TreeNode* buildTree(vector<int>& prorder, int preStart, int preEnd,
                        vector<int>& inord, int inStart, int inEnd,
                        unordered_map<int, int>& inMap) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(prorder[preStart]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(prorder, preStart + 1, preStart + numsLeft,
                               inord, inStart, inRoot - 1, inMap);
        root->right = buildTree(prorder, preStart + numsLeft + 1, preEnd,
                                inord, inRoot + 1, inEnd, inMap);

        return root;
    }
};

// Helper function to print the tree in a structured way
void printTree(TreeNode* root, string indent = "") {
    if (!root) return;
    cout << indent << root->val << endl;
    printTree(root->left, indent + "  L-");
    printTree(root->right, indent + "  R-");
}

int main() {
    Solution solution;
    vector<int> prorder = {3, 9, 20, 15, 7};
    vector<int> inord = {9, 3, 15, 20, 7};
    TreeNode* root = solution.buildTree(prorder, inord);

    // Print the tree structure
    cout << "Tree structure:" << endl;
    printTree(root);

    return 0;
}
