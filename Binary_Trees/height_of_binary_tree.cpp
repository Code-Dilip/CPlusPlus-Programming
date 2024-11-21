#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    Node(int val){
        data = val;
    }
};

int calcHeight(struct Node *root){
    if(root == nullptr){
        return 0;
    }
    return (max(calcHeight(root->left),calcHeight(root->right))+1);
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

    cout<<"Height of the binary tree is "<<calcHeight(root)<<endl;
    cout<<"\n";
}