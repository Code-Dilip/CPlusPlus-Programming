#include<iostream>
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

bool identical_or_not(node *root1, node *root2){
    if(root1==nullptr || root2==nullptr){
        return (root1==root2);
    }
    return ((root1->data==root2->data) && identical_or_not(root1->left, root2->left) && identical_or_not(root1->right, root2->right));
}

int main(){
    node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->right->left = new node(4);
    root1->right->right = new node(5);

    node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->right->left = new node(4);
    root2->right->right = new node(5);

    cout<<identical_or_not(root1, root2)<<endl;

    return 0;
}