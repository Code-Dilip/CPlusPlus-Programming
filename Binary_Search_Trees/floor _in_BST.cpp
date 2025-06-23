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

int floor(node *root, int key){
    int floor = -1;
    while(root){
        if(root->data == key) return root->data;
        else if(key < root->data){
            root = root->left;
        }
        else{
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
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

    cout<<floor(root, 8)<<endl;
    return 0;
}