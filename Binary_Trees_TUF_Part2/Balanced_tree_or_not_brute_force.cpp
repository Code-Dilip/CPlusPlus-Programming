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

int find_height(node *root){
    if(root==nullptr){
        return 0;
    }
    int lh = find_height(root->left);
    int rh = find_height(root->right);

    return (1+max(lh,rh));
}

bool balanced_or_not(node *root){
    if(root==nullptr){
        return true;
    }
    int lh = find_height(root->left);
    int rh = find_height(root->right);

    if((lh-rh)>1) return false;
    bool left = balanced_or_not(root->left);
    bool right = balanced_or_not(root->right);

    if(!left || !right){
        return false;
    }
    return true;
}

int main(){
    node *root1 = new node(1);

    root1->left = new node(3);
    root1->right = new node(2);

    root1->left->left = new node(5);
    root1->left->right = new node(4);

    root1->left->left->left = new node(7);
    root1->left->left->right = new node(6);

    node *root2 = new node(3);
    root2->left = new node(9);
    root2->right = new node(20);
    root2->right->left = new node(15);
    root2->right->right = new node(7);

    cout<<balanced_or_not(root1)<<endl;
    cout<<balanced_or_not(root2)<<endl;

    return 0;
}