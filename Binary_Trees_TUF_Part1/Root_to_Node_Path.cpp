#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

bool get_path(node *root, int x, vector <int> &path){
    if(root==nullptr){
        return false;
    }
    path.push_back(root->data);
    if(root->data==x){
        return true;
    }
    if(get_path(root->left, x, path)||get_path(root->right, x, path)) return true;
    path.pop_back();
    return false;
}


int main(){
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->left->right->right = new node(7);

    vector <int> path;
    node *Node = root;
    get_path(Node, 6, path);
    for(int val : path){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}