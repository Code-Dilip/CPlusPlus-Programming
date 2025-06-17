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

int max_diameter(node *root, int &maxi){
    if(root==nullptr){
        return 0;
    }
    int lh = max_diameter(root->left, maxi);
    int rh = max_diameter(root->right, maxi);

    maxi = max(maxi, (lh+rh));
    
    return (1+max(lh,rh));
}

int main(){
    node *root = new node(1);
    
    root->left = new node(2);
    root->right = new node(3);

    root->right->left = new node(4);
    root->right->left->left = new node(5);
    root->right->left->left->left = new node(6);
    
    root->right->right = new node(7);
    root->right->right->right = new node(8);
    root->right->right->right->right = new node(9);

    int maxi = 0;
    max_diameter(root, maxi);
    cout<<maxi<<endl;
}