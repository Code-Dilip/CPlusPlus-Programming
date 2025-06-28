#include<iostream>
#include<climits>
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

node *buildTree(vector <int> pre_order, int &i, long bound){
    if(i==pre_order.size() || pre_order[i]>bound) return nullptr;
    node *root = new node(pre_order[i++]);
    root->left = buildTree(pre_order, i, root->data);
    root->right = buildTree(pre_order, i, bound);
    return root;
}

node *buildBSTFromPreorder(vector <int> pre_order){
    int i = 0;
    return buildTree(pre_order, i, INT_MAX);
}


void preOrder_traversel(node *root){
    if(root == nullptr) return ;
    cout<<root->data<<" ";
    preOrder_traversel(root->left);
    preOrder_traversel(root->right);
}

int main(){
    vector <int> pre_order = {8,5,1,7,10,12};
    node *root = buildBSTFromPreorder(pre_order);
    preOrder_traversel(root);
    cout<<endl;
    return 0;
}
