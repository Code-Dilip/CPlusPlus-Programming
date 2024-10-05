#include<iostream>

int const n=100;
int arr[n];

class stack{
    public:
    int top = 0;
    void push(int val){
        top ++;
        arr[top] = val;
    }
    void pop(){
        top --;
    }
    int top(){
        return arr[top];
    }
    bool isEmpty()
}

int main(){
    return 0;
}