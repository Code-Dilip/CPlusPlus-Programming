#include<iostream>
#define n 100

using namespace std;

class Queue{
    int *arr;
    int front;
    int back;

    public:
    Queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enqueue(int x){
        if(back >= n){
            cout<<"Queue Overflow! "<<endl;
            return ;
        }
        if(front == -1){
            front ++;
        }
        back ++;
        arr[back] = x;
    }

    void dequeue(){
        if(front > back){
            cout<<"The Queue is Empty!"<<endl;
            return ;
        }
        front ++;
    }

    int peek(){
        if(front > back){
            cout<<"The Queue is Empty!"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front > back){
            return true;
        }
        return false;
    }

    void print(){
        if(front>-1 and back>-1){
            cout<<"[ ";
            for(int i=front;i<=back;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"]"<<endl;
        }
    }
};

int main(){
     
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.peek()<<endl;
    q.print();
    cout<<endl;

    q.dequeue();
    q.dequeue();
    cout<<q.peek()<<endl;
    q.print();
    cout<<q.empty()<<endl;
    cout<<endl;

    q.dequeue();
    q.peek();
    q.print();
    cout<<q.empty()<<endl;
    cout<<endl;
    
    return 0;
}