#include<iostream>
#include<queue>
#include<vector>
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

int max_height(node *root){
    if(root==nullptr){
        return 0;
    }

    int lh = max_height(root->left);
    int rh = max_height(root->right);

    return (1+max(lh,rh));
}

int main(){
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->left->right->right = new node(7);

    root->left->right->right->left = new node(8);

    cout<<max_height(root)<<endl;

    return 0;
}