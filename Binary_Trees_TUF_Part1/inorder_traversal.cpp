#include<iostream>
#include<vector>
#include<stack>
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

vector <int> in_order(node *root){
    vector <int> ans;
    stack <node *> st;
    node *Node = root;

    while(true){
        if(Node!=nullptr){
            st.push(Node);
            Node = Node->left;
        }
        else{
            if(st.empty()) break;
            Node = st.top();
            st.pop();
            ans.push_back(Node->data);
            Node = Node->right;
        }
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

    vector <int>ans = in_order(root);

    
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}