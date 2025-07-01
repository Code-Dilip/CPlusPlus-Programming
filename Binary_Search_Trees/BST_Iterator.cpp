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

class BST_iterator{
    private: 
    stack <node *> bst_stack;
    
    void pushAll(node *root){
        while(root!=nullptr){
            bst_stack.push(root);
            root = root->left;
        }
    }

    public:
    BST_iterator(node *root){
        pushAll(root);
    }

    node *next(){
        node *next_node = bst_stack.top();
        bst_stack.pop();
        if(next_node->right) pushAll(next_node->right);
        return next_node;
    }

    bool has_next(){
        return (!(bst_stack.empty()));
    }
};

void inorder_traversel(node *root){
    if(root==nullptr) return;
    inorder_traversel(root->left);
    cout<<root->data<<" ";
    inorder_traversel(root->right);
}

int main(){
    node *root = new node(7);
    root->left = new node(3);
    root->right = new node(15);
    root->right->left = new node(9);
    root->right->right = new node(20);

    inorder_traversel(root);
    cout<<endl;
    
    BST_iterator b = BST_iterator(root);
    cout<<(b.next())->data<<endl;
    cout<<b.has_next()<<endl;
    cout<<(b.next())->data<<endl;
    cout<<b.has_next()<<endl;
    cout<<(b.next())->data<<endl;
    cout<<b.has_next()<<endl;
    cout<<(b.next())->data<<endl;
    cout<<b.has_next()<<endl;
    cout<<(b.next())->data<<endl;
    cout<<b.has_next()<<endl;

    return 0;
}