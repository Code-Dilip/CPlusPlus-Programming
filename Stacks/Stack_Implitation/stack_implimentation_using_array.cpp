#include<iostream>
#define n 10
using namespace std;

class stack{
    public:
    int *arr;
    int top = -1;
    stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int x){
        if(top>=n){
            cout<<"Stack Overflow!"<<endl;
            return ;
        }
        top ++;
        arr[top] = x;
        return ;
    }

    void pop(){
        if(top<=-1){
            cout<<"Stack is empty!"<<endl;
            return ;
        }
        top --;
    }

    int seek(){
        if(top <= -1){
            cout<<"Stack is empty!"<<endl;
            return 0;
        }
        return arr[top];
    }

    bool isEmpty(){
        if(top == -1){
            return 1;
        }
        return 0;
    }

    void print(){
        if(top<=-1 || top>=n){
            return ;
        }
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return ;
    }
};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    s.print();
    return 0;
}