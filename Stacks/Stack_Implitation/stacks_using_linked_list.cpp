#include<iostream>

using namespace std;

class node {
    public:
    int data;
    node *prev;
    node *next;
    public:
    node (int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class stack  {
    node *top;
    node *bottom ;
    public: 
    stack(){
        top = nullptr;
        bottom = nullptr;
    }

    void push(int x){
        node *newp = new node(x);
        if(newp == nullptr){
            cout<<"Stack Overflow!"<<endl;
            return ;
        }
        if(top == nullptr){
            top = newp;
            bottom = newp;
            return ;
        }
        top->next = newp;
        newp->prev = top;
        top = newp;
    }

    void pop(){
        if(top == nullptr){
            cout<<"Stack is Empty!"<<endl;
            return;
        }
        node *toDelete = top;
        top = top->prev;
        if(top == nullptr){
            bottom = nullptr;
        }
        else{
            top->next = nullptr;
        }
        free(toDelete);
    }

    int seek(){
        if(top == nullptr){
            cout<<"Stack is Empty!"<<endl;
            return -1;
        }
        return top->data;
    }

    bool empty(){
        if(top == nullptr){
            return 1;
        }
        return 0;
    }

    void print(){
        if(bottom == nullptr){
            return ;
        }
        node *temp = bottom;
        cout<<"[ ";
        while(temp->next != nullptr){
            cout<<temp->data<<",";
            temp = temp->next;
        }
        cout<<temp->data<<"] "<<endl;
    }
};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.print();
    cout<<s.seek()<<endl;
    cout<<s.empty()<<endl;
    cout<<endl;

    s.pop();
    s.print();
    cout<<s.seek()<<endl;
    cout<<s.empty()<<endl;
    cout<<endl;

    s.pop();
    s.pop();
    s.pop();
    cout<<s.seek()<<endl;
    cout<<s.empty()<<endl;
    cout<<endl;

    return 0;
}