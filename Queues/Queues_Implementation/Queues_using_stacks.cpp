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


class Queue {
    stack s1;
    stack s2;
    public:
    void enqueue(int x){
        s1.push(x);
    }

    void dequeue(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is Empty!"<<endl;
            return ;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.seek());
                s1.pop();
            }
        }
        s2.pop();
    }

    int peek(){
        return s2.seek();
    }

    bool Empty(){
        if(s1.empty() && s2.empty()){
            return 1;
        }
        return 0;
    }
    
    void Print(){
        if(s2.empty()){
            s1.print();
            return ;
        }
        s2.print();
    }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.Print();
    cout<<q.Empty()<<endl;
    
    cout<<endl;
    q.dequeue();
    q.Print();
    cout<<q.peek()<<endl;
    cout<<q.Empty()<<endl;
    
    cout<<endl;
    q.dequeue();
    q.dequeue();
    q.Print();
    cout<<q.peek()<<endl;
    cout<<q.Empty()<<endl;

    return 0;
}