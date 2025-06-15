#include<iostream>
#include<vector>
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

void right_view(node *Node, int level, vector <int> &ans){
    if(Node == nullptr){
        return ;
    }
    if(ans.size()==level){
        ans.push_back(Node->data);
    }
    right_view(Node->right, level+1, ans);
    right_view(Node->left, level+1, ans);
}

int main(){
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
     root->left->right->left = new node(6);
    root->right->right = new node(7);

    vector <int> ans ;
    right_view(root, 0, ans);
    
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}