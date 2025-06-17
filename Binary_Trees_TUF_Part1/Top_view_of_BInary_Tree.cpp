#include<iostream>
#include<vector>
#include<queue>
#include<map>
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


vector <int> top_view(node *root){
    vector <int> ans;
    if(root==nullptr){
        return ans;
    }
    
    map<int,int> mp;
    queue<pair<node *, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto ele = q.front();
        q.pop();
        node *Node = ele.first;
        int level = ele.second;

        if(mp.find(level)==mp.end()){
            mp[level] = Node->data;
        }
        if(Node->left!=nullptr){
            q.push({Node->left, level-1});
        }
        if(Node->right!=nullptr){
            q.push({Node->right, level+1});
        }
    }
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}


int main(){
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->right->right = new node(7);

    vector <int> ans ;
    ans = top_view(root);
    
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}