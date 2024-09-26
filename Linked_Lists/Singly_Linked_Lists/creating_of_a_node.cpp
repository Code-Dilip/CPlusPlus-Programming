#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

int main(){

   node *head = new node(5);
   cout<<"head->data = "<<head->data<<endl;
   return 0;
}