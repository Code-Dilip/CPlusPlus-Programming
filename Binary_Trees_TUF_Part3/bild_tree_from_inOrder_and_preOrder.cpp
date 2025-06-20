#include<iostream>
#include<map>
#include<vector>
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

node *buildTree_PreIn(vector <int> &in_order, int is, int ie, vector <int> &pre_order, int ps, int pe, map<int,int> mp){
    if(is>ie || ps>pe) return nullptr;
    node *root = new node(pre_order[ps]);
    int in_root_idx = mp[root->data];
    int nums_left = in_root_idx - is;

    root->left = buildTree_PreIn(in_order, is, in_root_idx-1, pre_order, ps+1, ps+nums_left, mp);
    root->right = buildTree_PreIn(in_order, in_root_idx+1, ie, pre_order, ps+nums_left+1, pe, mp);

    return root;
}

node *buildTree(vector <int> &in_order, vector <int> &pre_order){
    if(in_order.size() != pre_order.size()) return nullptr;
    map<int, int> in_mp;
    for(int i=0;i<in_order.size();i++){
        in_mp[in_order[i]] = i;
    }
    node *root = buildTree_PreIn(in_order, 0, in_order.size()-1, pre_order, 0, pre_order.size()-1, in_mp);
    return root;
}
 
void in_order_traversel(node *root){
    if(root==nullptr){
        return ;
    }
    in_order_traversel(root->left);
    cout<<root->data<<" ";
    in_order_traversel(root->right);
}

int main(){
    vector <int> in_order = {40,20,50,10,60,30};
    vector <int> pre_order = {10,20,40,50,30,60};

    node *root = buildTree(in_order, pre_order);
    in_order_traversel(root);

    return 0;
}