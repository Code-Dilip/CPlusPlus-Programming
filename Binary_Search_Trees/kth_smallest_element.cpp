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

void kth_smallest_element(node *root, int k, int &cnt){
    if(root==nullptr) return ;
    kth_smallest_element(root->left, k, cnt);
    cnt ++;
    if(cnt==k){
        cout<<root->data<<" ";
        return ;
    }
    kth_smallest_element(root->right, k, cnt);
}

int main(){
    node *root = new node(5);
    root->left = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->left->left->right = new node(2);

    root->right = new node(7);
    root->right->left = new node(8);
    root->right->right = new node(9);
    int cnt = 0;
    kth_smallest_element(root, 3, cnt);
    cout<<endl;
    return 0;
}