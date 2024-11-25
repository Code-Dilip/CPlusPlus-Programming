#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    Node(int val){
        data = val;
    }
};

int height(struct Node *root){
    if(root == nullptr){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;
}

bool check_balanced_height(struct Node *root){
    if(root == nullptr){
        return true;
    }
    if(check_balanced_height(root->left)==false){
        return false;
    }
    if(check_balanced_height(root->right)==false){
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh) <= 1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    
    cout<<"\n";
    struct Node *root1 = new Node(1),*leaf1 = new Node(2),*leaf2 = new Node(3),*leaf3 = new Node(4) ;
    root1->left = leaf1;
    root1->right = leaf2;
    leaf1->left = leaf3;
    if(check_balanced_height(root1)){
        cout<<"Tree 1 is Balanced!";
    }
    else{
        cout<<"Tree 1 is UnBalanced!";
    }

    cout<<"\n";

    struct Node *root2 = new Node(1),*leaf21 = new Node(2),*leaf22 = new Node(3),*leaf23 = new Node(4),*leaf24 = new Node(5);
    root2->left = leaf21;
    root2->right = leaf22;
    leaf21->left = leaf23;
    leaf23->left = leaf24;
    if(check_balanced_height(root2)){
        cout<<"Tree 2 is Balanced!";
    }
    else{
        cout<<"Tree 2 is UnBalanced!";
    }

    cout<<"\n";
    return 0;
}