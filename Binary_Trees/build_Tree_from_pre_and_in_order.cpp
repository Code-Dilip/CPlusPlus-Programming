#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void inOrderTraversal(Node *root){
    if(root == nullptr){
        return ;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

int search_curr(int in_order[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(in_order[i] == curr){
            return i;
        }
    }
    return -1;
}

Node *buildTree(int pre_order[],int in_order[],int start,int end){
    if(start > end){
        return nullptr;
    }
    static int index = 0;
    int curr = pre_order[index];
    index ++;
    Node *node = new Node(curr);
    if(start == end){
        return node;
    }
    int pos = search_curr(in_order,start,end,curr);
    (node->left) = buildTree(pre_order,in_order,start,pos-1);
    (node->right) = buildTree(pre_order,in_order,pos+1,end);

    return node;
}

int main(){
    cout<<"\n";
    int pre_order[] = {1,2,4,3,5};
    int in_order[] = {4,2,1,5,3};

    Node *root = buildTree(pre_order,in_order,0,4);
    inOrderTraversal(root);
    return 0;
}