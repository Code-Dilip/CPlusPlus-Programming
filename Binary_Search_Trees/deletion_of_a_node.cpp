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

node *right_leaf_node(node *root){
    if(root->right==nullptr){
        return root;
    }
    return right_leaf_node(root->right);
}

node *helper(node *delete_node){
    if(delete_node->left==nullptr) return delete_node->right;
    else if(delete_node->right==nullptr) return delete_node->left;
    node *right_node = delete_node->right;
    node *left_right_leaf_node = right_leaf_node(delete_node->left);
    left_right_leaf_node->right = right_node;
    node *delete_node_left = delete_node->left;
    delete delete_node;
    return delete_node_left;
}

void deleteNode(node *root, int val){
    if(root==nullptr) return ;
    if(root->data==val) helper(root);
    while(root){
        if(val < root->data){
            if(root->left!=nullptr && root->left->data==val){
                root->left = helper(root->left);
                return ;
            }
            else{
                root = root->left;
            }
        }
        else{
            if(root->right!=nullptr && root->right->data==val){
                root->right = helper(root->right);
                return ;
            }
            else{
                root = root->right;
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
    node *root = new node(8);
    root->left = new node(5);
    root->left->left = new node(2);
    root->left->right = new node(7);
    root->left->left->left = new node(1);
    root->left->left->right = new node(3);
    root->left->left->right->right = new node(4);

    root->right = new node(12);
    root->right->left = new node(10);
    root->right->right = new node(13);

    in_order_traversel(root);
    deleteNode(root, 5);
    cout<<endl;
    in_order_traversel(root);
    cout<<endl;
    
    return 0;
}