#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    Node(int val){
        data = val;
    }
};

struct Node *LCA(struct Node *root,int n1,int n2){
    if(root == nullptr){
        return nullptr;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node *left = LCA(root->left,n1,n2);
    Node *right = LCA(root->right,n1,n2);
    if(left!=nullptr && right !=nullptr){
        return root;
    }
    if(left==nullptr && right==nullptr){
        return nullptr;
    }
    if(left == nullptr){
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
}

int findDistance(struct Node *root,int K,int distance){
    if(root == nullptr){
        return -1;
    }
    if(root->data == K){
        return distance;
    }
    int left = findDistance(root->left,K,distance+1);
    if(left!=-1){
        return left;
    }
    return findDistance(root->right,K,distance+1);
}

int distBtwNodes(struct Node *root,int n1,int n2){
    struct Node *lca = LCA(root,n1,n2);
    int d1 = findDistance(lca,n1,0);
    int d2 = findDistance(lca,n2,0);
    return (d1+d2);
}


int main(){
    
    cout<<"\n";
    struct Node *root = new Node(1),*leaf1 = new Node(2),*leaf2 = new Node(3),*leaf3 = new Node(4),*leaf4 = new Node(5),*leaf5 = new Node(6),*leaf6 = new Node(7),*leaf7 = new Node(8);
    root->left = leaf1;
    root->right = leaf2;
    leaf1->left = leaf3;
    leaf2->left = leaf4;
    leaf2->right = leaf5;
    leaf4->left = leaf6;
    leaf4->right = leaf7;

    int n1 = 6,n2 = 7;
    cout<<"Distance between the two nodes n1 and n2: ",distBtwNodes(root,n1,n2);
    cout<<"\n";
    return 0;
}