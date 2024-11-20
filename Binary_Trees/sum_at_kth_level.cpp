#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    Node(int val){
        data = val;
    }
};

int sumAtLevel(struct Node *root,int k){
    if(root == nullptr){
        cout<<"Empty Binary Tree!"<<endl;
        return -1;
    }
    queue<struct Node *>q;
    q.push(root);
    q.push(nullptr);
    int level = 0,sum = 0;
    
    while (!q.empty())
    {
        struct Node *node = q.front();
        q.pop();
        
        if(node != nullptr){
            if(level == k){
                sum += node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(nullptr);
            level ++;
        }
    }
    return sum;
}

int main(){
    cout<<"\n";

    struct Node *root = new Node(1),*leaf1 = new Node(2),*leaf2 = new Node(3),*leaf3 = new Node(4),*leaf4 = new Node(5),*leaf5 = new Node(6),*leaf6 = new Node(7);
    root->left = leaf1;
    root->right = leaf2;
    
    leaf1->left = leaf3;
    leaf1->right = leaf4;
    leaf2->left = leaf5;
    leaf2->right = leaf6;

    cout<<"Sum of binary tree at "<<2<<" level: "<<sumAtLevel(root,2);
    cout<<"\n";
}