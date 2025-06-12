#include<iostream>
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

void in_order_traversel(node *root){
    if(root==nullptr){
        return ;
    }
    in_order_traversel(root->left);
    cout<<root->data<<" ";
    in_order_traversel(root->right);
}

void pre_order_traversel(node *root){
    if(root==nullptr){
        return ;
    }
    cout<<root->data<<" ";
    pre_order_traversel(root->left);
    pre_order_traversel(root->right);
}

void post_order_traversel(node *root){
    if(root==nullptr){
        return ;
    }
    post_order_traversel(root->left);
    post_order_traversel(root->right);
    cout<<root->data<<" ";
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    in_order_traversel(root);
    cout<<"\n";
    pre_order_traversel(root);
    cout<<"\n";
    post_order_traversel(root);

    return 0;
}