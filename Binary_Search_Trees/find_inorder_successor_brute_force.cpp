#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node *right;
    node *left;
    node(int val){
        data = val;
        right = nullptr;
        left = nullptr;
    }
};

void inorder_traversel(node *root, vector <node *> &inorder){
    if(root==nullptr) return ;
    inorder_traversel(root->left, inorder);
    inorder.push_back(root);
    cout<<root->data<<" ";
    inorder_traversel(root->right, inorder);
}

node *find_inorder_successor(node *root, int val, vector <node *> inorder){

    for(auto it : inorder){
        if(it->data > val){
            return it;
        }
    }
    return nullptr;
}

int main(){
    node *root = new node(5);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->left->left->left = new node(1);

    root->right = new node(7);
    root->right->left = new node(6);
    root->right->right = new node(9);
    root->right->right->left = new node(8);
    root->right->right->right = new node(10);

    vector <node *> inorder;

    inorder_traversel(root, inorder);
    cout<<endl;
    cout<<find_inorder_successor(root, 8, inorder)->data<<endl;
    return 0;  
}