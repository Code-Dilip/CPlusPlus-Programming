#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *right;
    Node *left;
    Node(int val){
        data = val;
        right = nullptr;
        left = nullptr;
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

int main(){
    Node *root = new Node(1);
    Node *leaf1 = new Node(2);
    Node *leaf2 = new Node(3);
    Node *leaf3 = new Node(4);
    Node *leaf4 = new Node(5);
    Node *leaf5 = new Node(6);
    Node *leaf6 = new Node(7);

    root->left = leaf1;
    root->right = leaf2;
    leaf1->left = leaf3;
    leaf1->right = leaf4;
    leaf2->left = leaf5;
    leaf2->right = leaf6;
    
    cout<<"\n";
    preOrderTraversal(root);

    cout<<"\n"<<endl;
    return 0;
}