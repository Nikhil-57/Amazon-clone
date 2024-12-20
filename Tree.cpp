#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node*left;
    struct Node*right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

int main(){
    struct Node* root = new Node(1);
    root->left->right = new Node(2);
    root->left->right = new Node(3);
    return 0;

}