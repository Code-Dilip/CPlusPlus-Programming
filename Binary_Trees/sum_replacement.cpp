#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    Node(int val){
        data = val;
    }
};

void sum_replacement(struct Node *root){
    if(root == nullptr){
        return ;
    }
    sum_replacement(root->left);
    sum_replacement(root->right);

    if(root->left != nullptr){
        root->data += root->left->data;
    }
    if(root->right != nullptr){
        root->data += root->right->data;
    }
}

void preOrderTraversal(struct Node *root){
    if(root == nullptr){
        return ;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main(){

    cout<<"\n";

    struct Node *root = new Node(1),*leaf1 = new Node(2),*leaf2 = new Node(3),*leaf3 = new Node(4),*leaf4 = new Node(5),*leaf5 = new Node(6),*leaf6 = new Node(7);
    root->left = leaf1;
    root->right = leaf2;
    
    leaf1->left = leaf3;
    leaf1->right = leaf4;
    leaf2->left = leaf5;
    leaf2->right = leaf6;
     
    cout<<"Binary Tree before sum replacement: ";
    preOrderTraversal(root);
    sum_replacement(root);
    cout<<"\nBinary Tree after sum replacement: ";
    preOrderTraversal(root);

    cout<<"\n";
    return 0;
}