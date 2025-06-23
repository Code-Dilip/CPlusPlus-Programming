#include<iostream>
using namespace std;

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

void count(node *root, int &cnt){
    if(root==nullptr) return ;
    count(root->left, cnt);
    cnt ++;
    count(root->right, cnt);
}

int count_nodes(node *root){
    int cnt = 0;
    count(root, cnt);
    return cnt;
}

void kth_largest_element(node *root, int N, int k, int &cnt){
    if(root==nullptr) return ;
    kth_largest_element(root->left, N, k, cnt);
    cnt ++;
    if(cnt==(N-k)+1){
        cout<<root->data<<" ";
        return ;
    }
    kth_largest_element(root->right, N, k, cnt);
}

void inorder_traversel(node *root){
    if(root==nullptr) return ;
    inorder_traversel(root->left);
    cout<<root->data<<" ";
    inorder_traversel(root->right);
}

int main(){
    node *root = new node(5);
    root->left = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->left->left->right = new node(2);

    root->right = new node(7);
    root->right->left = new node(6);
    root->right->right = new node(8);

    inorder_traversel(root);
    cout<<endl;
    
    int N = count_nodes(root);
    cout<<N<<endl;

    int cnt = 0;
    kth_largest_element(root, N, 1, cnt);
    cout<<endl;
    return 0;
}