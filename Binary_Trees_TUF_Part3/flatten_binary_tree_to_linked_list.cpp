#include<iostream>
#include<stack>
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


void flatten_to_list(node *root, node *&prev){
    if(root==nullptr) return;
    flatten_to_list(root->right, prev);
    flatten_to_list(root->left, prev);
    root->right = prev;
    root->left = nullptr;
    prev = root;
}


void in_order_traversel(node *root){
    if(root==nullptr) return ;
    in_order_traversel(root->left);
    cout<<root->data<<" ";
    in_order_traversel(root->right);
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    
    root->right = new node(5);
    root->right->right = new node(6);
    root->right->right->left = new node(7);

    node *prev = nullptr;
    flatten_to_list(root, prev);
    in_order_traversel(root);

    return 0;
}