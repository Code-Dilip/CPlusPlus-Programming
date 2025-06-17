#include<iostream>
#include<vector>
#include<queue>
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

int max_width(node *root){
    if(root==nullptr){
        return 1;
    }
    int ans;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    
    while(!q.empty()){
        int min_id = q.front().second;
        int curr_id, first_id, last_id;
        int size = q.size();
        for(int i=0;i<size;i++){
            curr_id = q.front().second - min_id;
            node *Node = q.front().first;
            q.pop();
            if(i==0)first_id = curr_id;
            if(i==size-1)last_id = curr_id;

            if(Node->left) q.push({Node->left, curr_id*2+1});
            if(Node->right) q.push({Node->right, curr_id*2+2});
        }
        ans = max(ans, last_id-first_id+1);
    }
    return ans;
}

int main(){
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    root->left->left->left = new node(8);
    root->left->left->right = new node(9);
    root->left->right->left = new node(10);
    root->left->right->right = new node(11);
    root->right->left->left = new node(12);
    root->right->left->right = new node(13);
    root->right->right->left = new node(14);
    root->right->right->right = new node(15);
    

    cout<<max_width(root)<<endl;

    return 0;
}