#include<iostream>
#include<queue>

using namespace std;

struct Node {
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    Node(int val){
        data = val;
    }
};

void right_view(struct Node *root){
    if(root == nullptr){
        return;
    }
    queue<struct Node *>q;
    q.push(root);
    
    while(!q.empty()){
        int n = q.size();
        struct Node *curr;
        for(int i=0;i<n;i++){
            curr =  q.front();
            q.pop();
            if(i == n-1){
                cout<<curr->data<<" ";
            }
        }
        if(curr->left!=nullptr){
            q.push(root->left);
        }
        if(curr->right!=nullptr){
            q.push(root->right);
        }
    }
}

int main(){
    
    cout<<"\n";
    struct Node *root1 = new Node(1),*leaf1 = new Node(2),*leaf2 = new Node(3),*leaf3 = new Node(4),*leaf4 = new Node(5),*leaf5 = new Node(6),*leaf6 = new Node(7) ;
    root1->left = leaf1;
    root1->right = leaf2;
    leaf1->left = leaf3;
    leaf2->left = leaf4;
    leaf2->right = leaf5;
    leaf4->left = leaf6;

    cout<<"\n";

    struct Node *root2 = new Node(1),*leaf21 = new Node(2),*leaf22 = new Node(3),*leaf23 = new Node(4),*leaf24 = new Node(5);
    root2->left = leaf21;
    root2->right = leaf22;
    leaf21->left = leaf23;
    leaf23->left = leaf24;
    
    cout<<"The right view of 1 Binary Tree :";
    right_view(root1);

    cout<<"\n";
    
    cout<<"The left view of 2 Binary Tree: ";
    right_view(root2);

    return 0;
}