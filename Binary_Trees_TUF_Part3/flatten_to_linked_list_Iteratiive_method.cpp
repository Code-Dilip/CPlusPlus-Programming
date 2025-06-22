#include<iostream>
#include<stack>
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


void flatten_to_list(node *root){
    stack <node *> st;
    st.push(root);
    while(!st.empty()){
        node *curr = st.top();
        st.pop();
        if(curr->right!=nullptr) st.push(curr->right);
        if(curr->left!=nullptr) st.push(curr->left);
        if(!st.empty()) curr->right = st.top();
        curr->left = nullptr;
    }
}


void in_order_traversel(node *root){
    if(root==nullptr) return ;
    in_order_traversel(root->left);
    cout<<root->data<<" ";
    in_order_traversel(root->right);
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    
    root->right = new node(5);
    root->right->right = new node(6);
    root->right->right->left = new node(7);

    flatten_to_list(root);
    in_order_traversel(root);

    return 0;
}