#include<iostream>
#include<vector>
#include<map>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;
    node (int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

node *buildTree_PostIn(vector <int> in_order, int is, int ie, vector <int> post_order, int ps, int pe, map<int, int> in_mp){
    if(is>ie || ps>pe) return nullptr;
    node *root = new node(post_order[pe]);
    int in_root_idx = in_mp[root->data];
    int nums_left = in_root_idx - is;

    root->left = buildTree_PostIn(in_order, is, in_root_idx-1, post_order, ps, ps+nums_left-1, in_mp);
    root->right = buildTree_PostIn(in_order, in_root_idx+1, ie, post_order, ps+nums_left, pe-1, in_mp);

    return root;
}

node *buildTree(vector <int> in_order, vector <int> post_order){
    if(in_order.size() != post_order.size()){
        return nullptr;
    }
    map<int, int> in_mp;
    for(int i=0;i<in_order.size();i++){
        in_mp[in_order[i]] = i;
    }
    node *root = buildTree_PostIn(in_order, 0, in_order.size()-1, post_order, 0, post_order.size()-1, in_mp);
    return root;
}

void in_order_traversel(node *root){
    if(root==nullptr) return ;

    in_order_traversel(root->left);
    cout<<root->data<<" ";
    in_order_traversel(root->right);
}

int main(){
    vector <int> in_order = {40,20,50,10,60,30};
    vector <int> post_order = {40,50,20,30,60,10};

    node *root = buildTree(in_order, post_order);
    in_order_traversel(root);

    return 0;
}