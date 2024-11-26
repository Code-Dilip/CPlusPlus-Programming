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

void LeftView(struct Node *root){
    if(root == nullptr){
        return ;
    }
    queue<struct Node *>q;
    q.push(root);

    while (!q.empty())
    {
        struct Node *curr;
        int n = q.size();
        for(int i=0;i<n;i++){
            curr = q.front();
            q.pop();
            if(i==0){
                cout<<curr->data<<" ";
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        cout<<"\n";
    }
}

int main(){
    
    cout<<"\n";
    struct Node *root = new Node(1),*leaf1 = new Node(2),*leaf2 = new Node(3),*leaf3 = new Node(4),*leaf4 = new Node(5),*leaf5 = new Node(6),*leaf6 = new Node(7);
    root->left = leaf1;
    root->right = leaf2;
    leaf1->left = leaf3;
    leaf2->left = leaf4;
    leaf2->right = leaf5;
    leaf4->left = leaf6;
    
    cout<<"Left view of the Binary Tree: \n";
    LeftView(root);
    cout<<"\n";
    return 0;
}