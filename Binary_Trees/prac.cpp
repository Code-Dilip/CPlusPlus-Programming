#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void inOrderTraversal(struct Node *root){
    if(root == nullptr){
        return ;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

int search_pos(int inOrder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inOrder[i] == curr){
            return i;
        }
    }
    return -1;
}

struct Node *buildTree(int postOrder[],int inOrder[],int start,int end){
    if(start > end){
        return nullptr;
    }
    static int index = end;
    int curr = inOrder[index];
    index --;
    struct Node *node = new Node(curr);

    if(start == end){
        return node;
    }
    int pos = search_pos(inOrder,start,end,curr);
    node->right = buildTree(postOrder,inOrder,pos+1,end);
    node->left = buildTree(postOrder,inOrder,start,pos-1);

    return node;
}

int main(){
    cout<<"\n";
    int postOrder[] = {4,2,5,3,1};
    int inOrder[] = {4,2,1,5,3};

    struct Node *root = buildTree(postOrder,inOrder,0,4);
    inOrderTraversal(root);
    cout<<"\n";
}
