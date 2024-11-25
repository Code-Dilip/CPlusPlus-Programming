#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *left = nullptr;
    struct Node *right = nullptr;
    Node(int val){
        data = val;
    }
};

bool check_balanced_height(struct Node *root,int *height){
    static int *lh = 0,*rh = 0;
    if(root == nullptr){
        return true;
    }
    if(check_balanced_height(root->left,lh)==false){
        return false;
    }
    if(check_balanced_height(root->right,rh)==false){
        return false;
    }
    height = max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    
    cout<<"\n";
    struct Node *root1 = new Node(1),*leaf1 = new Node(2),*leaf2 = new Node(3),*leaf3 = new Node(4) ;
    root1->left = leaf1;
    root1->right = leaf2;
    leaf1->left = leaf3;

    cout<<"\n";

    struct Node *root2 = new Node(1),*leaf21 = new Node(2),*leaf22 = new Node(3),*leaf23 = new Node(4),*leaf24 = new Node(5);
    root2->left = leaf21;
    root2->right = leaf22;
    leaf21->left = leaf23;
    leaf23->left = leaf24;
    
    int height = 0;

    if(check_balanced_height(root2,&height)){
        cout<<"Tree 1 is Balanced!";
    }
    else{
        cout<<"Tree 1 is Unbalanced!";
    }

    cout<<"\n";
    
    height = 0;
    if(check_balanced_height(root2,&height)){
        cout<<"Tree 2 is Balanced!";
    }
    else{
        cout<<"Tree 2 is Unbalanced!";
    }

    return 0;
}