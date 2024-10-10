#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *next;
    public:
    node(int val){
        data = val;
        next = nullptr;
    }
};

class  Queue {
    node *front;
    node *back;
    public:
    Queue(){
        front = nullptr;
        back = nullptr;
    }

    void enqueue(int x){
        node *newp = new node(x);
        if(newp == nullptr){
            cout<<"Queue Overflow!"<<endl;
            return;
        }
        if(front == nullptr){
            back = newp;
            front = newp;
            return ;
        }
        back->next = newp;
        back = newp;
    }

    void dequeue(){
        if(front == nullptr){
            cout<<"Queue is Empty!"<<endl;
            return ;
        }
        node *delNode = front ;
        front = front->next;
        free(delNode);
        delNode = nullptr;
    }

    int peek(){
        if(front == nullptr){
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }
        return front->data;
    }
    
    bool empty(){
        if(front == nullptr){
            return true;
        }
        return false;
    }

    void print(){
        node *temp = front;
        cout<<"[ ";
        if(front != nullptr){
            while(temp->next != nullptr){
                cout<<temp->data<<",";
                temp = temp->next;
                }
            cout<<temp->data<<" ]"<<endl;
        }
    }
};

int main(){

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();
    cout<<q.peek()<<endl;
    cout<<q.empty()<<endl;
    
    cout<<endl;
    q.dequeue();
    q.print();
    cout<<q.peek()<<endl;
    cout<<q.empty()<<endl;
    
    cout<<endl;
    q.dequeue();
    q.dequeue();
    q.print();
    cout<<q.peek()<<endl;
    cout<<q.empty()<<endl;

    return 0;
}