#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *right;
    node *left;
    node(int val){
        data = val;
        right = nullptr;
        left = nullptr;
    }
};

bool is_symmetry(node *left_node , node *right_node){
    if(left_node==nullptr || right_node==nullptr){
        return (left_node==right_node);
    }
    if(left_node->data!=right_node->data){
        return false;
    }
    return (is_symmetry(left_node->left, right_node->right) && is_symmetry(left_node->right, right_node->left));
}

bool check_symmetry(node *root){
    return (root==nullptr || is_symmetry(root->left, root->right));
}

int main(){
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(2);
    root1->left->left = new node(3);
    root1->left->right = new node(4);
    root1->right->left = new node(4);
    root1->right->right = new node(3);

    node *root2 = new node(1);
    root2->left = new node(2);
    root2->left->right = new node(3);
    root2->right = new node(2);
    root2->right->right = new node(3);

    cout<<check_symmetry(root1)<<endl;
    cout<<check_symmetry(root2)<<endl;

    return 0;
}