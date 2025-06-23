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

int ceil(node *root, int key){
    int ceil = -1;
    while (root)
    {
        if(root->data == key){
            ceil = root->data;
            return ceil;
        }
        else if(root->data > key){
            ceil = root->data;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return ceil;
}

int main(){
    node *root = new node(10);
    root->left = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(6);
    root->left->left->left = new node(2);
    root->left->left->right = new node(4);
    
    root->right = new node(13);
    root->right->left = new node(11);
    root->right->right = new node(14);

    cout<<ceil(root, 8)<<endl;
    return 0;
}