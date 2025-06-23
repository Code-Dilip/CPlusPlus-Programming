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

void in_order_traversel(node *root){
    if(root==nullptr) return ;
    in_order_traversel(root->left);
    cout<<root->data<<" ";
    in_order_traversel(root->right);
}

void child_sum_property(node *root){
    if(root==nullptr){
        return ;
    }
    int sum = 0;
    if(root->left) sum += root->left->data;
    if(root->right) sum += root->right->data;

    if(sum >= root->data) root->data = sum;
    if(root->left) root->left->data = root->data;
    else if(root->right) root->right->data = root->data;
    

    child_sum_property(root->left);
    child_sum_property(root->right);

    sum = 0;
    if(root->left) sum += root->left->data;
    if(root->right) sum += root->right->data;
    if(root->right || root->left) root->data = sum; 
}

int main(){
    node *root = new node(2);
    root->left = new node(35);
    root->left->left = new node(2);
    root->left->right = new node(3);
    
    root->right = new node(10);
    root->right->left = new node(5);
    root->right->right = new node(2);
    
    in_order_traversel(root);
    child_sum_property(root);
    cout<<endl;
    in_order_traversel(root);
    return 0;
}