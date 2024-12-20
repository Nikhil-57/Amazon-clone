#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Lowest Common Ancestor is that common ancestor those are depper in level as well common among the ancestor of node 

class Solution{
    public:
        TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){ 
            if(root == NULL || root == p || root == q) return root;

            TreeNode* left = LowestCommonAncestor(root->left, p, q);
            TreeNode* right = LowestCommonAncestor(root->right, p, q);

            if(left == NULL){
                return right;
            }else if(right == NULL){
                return left;
            }else{
                return root;
            }
        }
};

int main() {
    // Create an example tree:
    //     1
    //    / \
    //   2   2
    //  / \ / \
    // 3  4 4  3

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution Sol;
    TreeNode* result = Sol.LowestCommonAncestor(root, root->left->left, root->left->right);
    
    if(result) {
        cout << "Lowest Common Ancestor: " << result->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found" << endl;
    }

    return 0;
}
