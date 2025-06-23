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

void insert_node(node *root, int val){
   if(root==nullptr){
    root = new node(val);
    return ;
   }
   while(true){
    if(val < root->data){
        if(root->left!=nullptr) root = root->left;
        else{
            root->left = new node(val);
            return ;
        }
    }
    else{
        if(root->right!=nullptr) root = root->right;
        else{
            root->right = new node(val);
            return ;
        }
    }
   }
}

void in_order_traversel(node *root){
    if(root==nullptr) return ;
    in_order_traversel(root->left);
    cout<<root->data<<" ";
    in_order_traversel(root->right);
}


int main(){
    node *root = new node(10);
    root->left = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(6);
    root->left->left->left = new node(2);
    root->left->left->right = new node(4);
    
    root->right = new node(13);
    root->right->left = new node(11);
    root->right->right = new node(14);

    in_order_traversel(root);
    insert_node(root, 0);
    cout<<endl;
    in_order_traversel(root);
    cout<<endl;
    
    return 0;
}