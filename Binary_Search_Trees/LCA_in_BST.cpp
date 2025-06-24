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

node *LCA(node *root, int x, int y){
    if(root==nullptr) return root;
    if(x<root->data && y<root->data) return root->left;
    if(x>root->data && y>root->data) return root->right;
    return root;
}

int main(){
    node *root = new node(6);
    root->left = new node(2);
    root->left->left = new node(0);
    root->left->right = new node(4);
    root->left->right->left = new node(3);
    root->left->right->right = new node(5);
    
    root->right = new node(8);
    root->right->left = new node(7);
    root->right->right = new node(9);

    cout<<(LCA(root,5,0)->data)<<endl;
    cout<<(LCA(root,2,0)->data)<<endl;
    cout<<(LCA(root,3,9)->data)<<endl;

    return 0;
}