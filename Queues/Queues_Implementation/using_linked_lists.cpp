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

class Queue{
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
            return ;
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
        node *temp = front;
        front = front->next;
        delete temp;
        temp = nullptr;
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
            return 1;
        }
        return 0;
    }

    void print(){
        if(front == nullptr){
            cout<<"Queue is Empty!"<<endl;
            return ;
        }
        node *temp = front;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
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
    q.dequeue();
    q.dequeue();
    q.print();
    q.peek();
    cout<<q.empty()<<endl;
    q.dequeue();
    
    return 0;
}
