#include<iostream>
#include<vector>
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

bool isLeaf(node *root){
    if(root->left==nullptr && root->right==nullptr){
        return 1;
    }
    return 0;
}

void left_boundary_traversel(node *root, vector <int> &res){
    if(root==nullptr) return ;
    root = root->left;
    while(root){
        if(!isLeaf(root)) res.push_back(root->data);
        if(root->left) root = root->left;
        else root = root->right;
    }
}

void insertLeafs(node *root, vector <int> &res){
    if(root==nullptr){
        return ;
    }
    insertLeafs(root->left, res);
    insertLeafs(root->right, res);

    if(isLeaf(root)) res.push_back(root->data);
}

void right_boundary_traversel(node *root, vector <int> &res){
    if(root==nullptr) return ;
    vector <int> temp;
    root = root->right;
    
    while (root)
    {
        if(!isLeaf(root)) temp.push_back(root->data);
        if(root->right) root = root->right;
        else root = root->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}

vector <int> boundary_traversel(node *root){
    vector <int> res;
    if(root==nullptr){
        return res;
    }
    res.push_back(root->data);
    left_boundary_traversel(root, res);
    insertLeafs(root, res);
    right_boundary_traversel(root, res);
    return res;
}

int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->left->right = new node(4);
    root->left->left->right->left = new node(5);
    root->left->left->right->right = new node(6);

    root->right = new node(7);
    root->right->right = new node(8);
    root->right->right->left = new node(9);
    root->right->right->left->left = new node(10);
    root->right->right->left->right = new node(11);

    vector <int> res = boundary_traversel(root);

    for(int val : res){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}