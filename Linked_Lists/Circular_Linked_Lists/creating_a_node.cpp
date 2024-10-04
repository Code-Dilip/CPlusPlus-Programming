#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = nullptr;
    }
};

int main(){
    node *tail = new node(1);
    cout<<"\nTail->data = "<<(tail->data)<<endl;
    cout<<"Tail->next = "<<(tail->next)<<endl;
    return 0;
}