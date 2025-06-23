#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node (int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

node *search_key(node *root, int key){
    while(root!=nullptr && root->data!=key){
        if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return root;
}

void in_order_traversel(node *root){
    if(root==nullptr) return ;
    in_order_traversel(root->left);
    cout<<root->data<<" ";
    in_order_traversel(root->right);
}

int main(){
    node *root = new node(8);
    root->left = new node(5);
    root->left->left = new node(4);
    root->left->right = new node(7);
    root->left->right->left = new node(6);

    root->right = new node(12);
    root->right->left = new node(10);
    root->right->right = new node(14);
    root->right->right->left = new node(13);

    node *key_node = search_key(root, 12);
    cout<<key_node->data<<endl;
    return 0;
}