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

node *lowest_common_ansestor(node *root, int x, int y){
    if(root==nullptr || root->data==x || root->data==y){
        return root;
    }
    node *left = lowest_common_ansestor(root->left, x, y);
    node *right = lowest_common_ansestor(root->right, x, y);

    if(left==nullptr){
        return right;
    }
    else if(right==nullptr){
        return left;
    }
    else{
        return root;
    }
}

int main(){
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);
    
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(8);
    root->right->right = new node(9);

    root->left->right->left = new node(6);
    root->left->right->right = new node(7);

    node *res = lowest_common_ansestor(root, 4,7);
    cout<<res->data<<endl;
    res = lowest_common_ansestor(root, 5,9);
    cout<<res->data<<endl;
    res = lowest_common_ansestor(root, 2,6);
    cout<<res->data<<endl;

    return 0;
}