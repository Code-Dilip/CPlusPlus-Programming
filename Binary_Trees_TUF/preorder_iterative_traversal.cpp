#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node *left ;
    node *right ;

    node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

vector <int> pre_order(node *root){
    vector <int> ans = {};
    if(root == nullptr){
        return ans;
    }

    stack <node *> s;
    s.push(root);
    while(!s.empty()){
        node *Node = s.top();
        s.pop();

        if(Node->right!=nullptr)s.push(Node->right);
        if(Node->left!=nullptr)s.push(Node->left);
        
        ans.push_back(Node->data);
    }
    return ans;
}


int main(){
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector <int>ans = pre_order(root);

    
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}