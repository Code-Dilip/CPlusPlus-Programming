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

int find_height(node *root){
    if(root==nullptr){
        return 0;
    }
    int lh = find_height(root->left);
    int rh = find_height(root->right);

    return (1+max(lh,rh));
}

void find_diameter(node *root, int &max_dia){
    if(root==nullptr){
        return ;
    }
    int lh = find_height(root->left);
    int rh = find_height(root->right);

    max_dia = max(max_dia, (lh+rh));
    
    find_diameter(root->left, max_dia);
    find_diameter(root->right, max_dia);
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
    find_diameter(root, maxi);
    cout<<maxi<<endl;
}