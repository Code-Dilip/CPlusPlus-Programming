#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node *left ;
    node *right ;

    node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> BFS_traversal(node *root){
   if(root==nullptr){
    return {{}};
   }

   queue <node *> q;
   q.push(root);
   vector <vector<int>> ans;

   while(!q.empty()){
    int n = q.size();
    vector <int> level;
    for(int i=0;i<n; i++){
        node *Node = q.front();
        q.pop();

        if(Node->left!=nullptr){
            q.push(Node->left);
        }
        if(Node->right!=nullptr){
            q.push(Node->right);
        }
        level.push_back(Node->data);
    }
    ans.push_back(level);
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

    vector <vector<int>> ans = BFS_traversal(root);

    for(vector <int> level: ans){
        for(int val : level){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    return 0;
}