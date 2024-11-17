#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void preOrderTraversal(Node *root){
    if(root == nullptr){
        return ;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root){
    if(root == nullptr){
        return ;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

int main(){

    Node *root=new Node(1),*leaf1=new Node(2), *leaf2=new Node(3), *leaf3=new Node(4),*leaf4=new Node(5),*leaf5=new Node(6),*leaf6=new Node(7);
    root->left = leaf1;
    root->right = leaf2;
    leaf1->left = leaf3;
    leaf1->right = leaf4;
    leaf2->left = leaf5;
    leaf2->right = leaf6;

    cout<<"\nPre Order Traversal:";
    preOrderTraversal(root);
    cout<<"\nIn Order Traversal:";
    inOrderTraversal(root);
    cout<<endl;

    return 0;
}