#include<iostream>
#include<climits>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool helper(node *root, long min_val, long max_val){
    if(root==nullptr) return true;
    if(root->data<=min_val || root->data>=max_val) return false;
    return (helper(root->left, min_val, root->data) && helper(root->right, root->data, max_val));
}

bool isValidBST(node *root){
    return helper(root, INT_MIN, INT_MAX);
} 

int main(){
    node *root = new node(13);
    root->left = new node(10);
    root->right = new node(15);
    root->left->left = new node(7);
    root->left->right = new node(12);
    root->left->left->right = new node(9);
    root->left->left->right->left = new node(8);

    root->right->left = new node(14);
    root->right->right = new node(17);
    root->right->right->left = new node(16);

    node *root2 = new node(5);
    root2->left = new node(1);
    root2->right = new node(6);
    root2->right->left = new node(4);
    root2->right->right = new node(8);

    cout<<isValidBST(root)<<endl;
    cout<<isValidBST(root2)<<endl;
    return 0;
}