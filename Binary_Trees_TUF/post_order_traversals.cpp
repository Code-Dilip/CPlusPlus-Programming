#include<iostream>
#include<stack>
#include<vector>
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

vector <int> post_order(node *root){
    vector <int> ans ;
    stack <node *> st;
    node *curr = root;
    node *temp;

    while(curr!=nullptr || (!st.empty())){
        if(curr!=nullptr){
            st.push(curr);
            curr = curr->left;
        }
        else{
            temp = st.top()->right;
            if(temp==nullptr){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp==st.top()->right){
                    temp = st.top();
                    st.pop();
                }
                ans.push_back(temp->data);
            }
            else{
                curr = temp;
            }
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

    vector <int>ans = post_order(root);

    
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}