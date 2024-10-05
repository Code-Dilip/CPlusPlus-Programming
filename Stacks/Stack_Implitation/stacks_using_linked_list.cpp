#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *prev;
    node *next;
    node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class stack{
    public:
    node *head;
    node *top;
    stack(){
        head = nullptr;
        top = nullptr;
    }

    void push(int val){
        node *newp = new node(val);
        if(newp == nullptr){
            cout<<"Stack Overflow!"<<endl;
            return ;
        }
        if(top == nullptr){
            top = newp;
            head = top;
            return ;
        }
        top->next = newp;
        newp->prev = top;
        top = newp;
    }
    
    void pop(){
        if(top==nullptr){
            cout<<"Stack is Empty!"<<endl;
            return ;
        }
        node *temp = top;
        top->next = nullptr;
        top = top->prev;
        free(temp);
    }

    int seek(){
        if(top==nullptr){
            cout<<"Stack is Empty!"<<endl;
            return 0;
        }
        return top->data;
    }

    bool isEmpty(){
        if(top == nullptr){
            return 1;
        }
        return 0;
    }

    void print(){
        node *temp = head;
        while(temp->next != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    cout<<s.isEmpty()<<endl;

    s.pop();
    s.pop();
    s.print();
    cout<<s.seek()<<endl;

    s.pop();
    s.pop();
    s.pop();
    s.print();
    cout<<s.seek()<<endl;
    cout<<s.isEmpty()<<endl;

    return 0;
}