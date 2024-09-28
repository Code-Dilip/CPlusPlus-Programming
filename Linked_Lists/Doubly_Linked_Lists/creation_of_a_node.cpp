#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;
    node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

int main(){
    node *head = new node(1);
    cout<<endl;
    cout<<"head->data = "<<(head->data)<<endl;
    cout<<"head->prev = "<<(head->prev)<<endl;
    cout<<"head->next = "<<(head->next)<<endl;

    return 0;
}