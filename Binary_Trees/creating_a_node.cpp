#include<iostream>

using namespace std;

class Node{
    Node *right;
    Node *left;
    public:
    int data;
    Node(int val){
        data = val;
        right = nullptr;
        left = nullptr;
    }
};

int main(){

    Node n1(2);
    cout<<"\n"<<endl;
    cout<<"Data of the Node: "<<n1.data<<endl;
    return 0;
}