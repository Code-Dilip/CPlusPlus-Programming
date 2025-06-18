#include<iostream>
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

bool root_to_node_path(node *root, int x, vector <int> &path){
    if(root==nullptr){
        return false;
    }
    path.push_back(root->data);
    if(x==root->data){
        return true;
    }
    if(root_to_node_path(root->left, x, path) || root_to_node_path(root->right, x, path)) return true;
    
    path.pop_back();
    return false;
}

int lowest_common_ancestor(node *root, int x, int y){
    vector <int> path_x, path_y;
    root_to_node_path(root, x, path_x);
    root_to_node_path(root, y, path_y);

    int m;
    if(path_x.size() > path_y.size()){
        m = path_x.size();
    }
    else{
        m = path_y.size();
    }
    for(int i=0;i<m;i++){
        if(path_x[i]!=path_y[i]){
            return path_x[i-1];
        }
        else{
            continue;
        }
    }
    return -1;
}

int main(){
    node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);
    
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(8);
    root->right->right = new node(9);

    root->left->right->left = new node(6);
    root->left->right->right = new node(7);

    cout<<lowest_common_ancestor(root, 4,7)<<endl;
    cout<<lowest_common_ancestor(root, 5,9)<<endl;
    cout<<lowest_common_ancestor(root, 2,6)<<endl;

    return 0;
}