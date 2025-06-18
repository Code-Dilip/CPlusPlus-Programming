#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
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

vector <vector<int>> zig_zag_traversel(node *root){
    vector <vector<int>> ans;
    if(root==nullptr){
        return ans;
    }
    queue<node *> q;
    q.push(root);
    
    bool left_to_right = 1;
    while(!q.empty()){
        int size = q.size();
        vector <int> level(size, 0);
        for(int i=0;i<size;i++){
            node *Node = q.front();
            q.pop();
            if(left_to_right){
                level[i] = Node->data;
            }
            else{
                level[size-1-i] = Node->data;
            }
            if(Node->left) q.push(Node->left);
            if(Node->right) q.push(Node->right);
        }
        ans.push_back(level);
        left_to_right = !left_to_right;
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

    vector <vector<int>> ans = zig_zag_traversel(root);
    for(vector <int> level : ans){
        for(int val : level){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}