#include<iostream>
#include<stack>
using namespace std;

class min_stack{
    public:
    stack<long long int> s;
    int min_val ;
    void push(int val){
        if(s.empty()){
            s.push(val);
            min_val = val;
        }
        else{
            if(val<min_val){
                s.push ((long long)2*val-min_val);
                min_val = val;
            }
            else{
                s.push(val);
            }
        }
    }

    void pop(){
        if(s.top()<min_val){
            min_val = 2*min_val-s.top();
        }
        s.pop();
    }

    int top(){
        if(s.top()<min_val){
            return min_val;
        }return s.top();
    }

    int getMin(){
        return min_val;
    }

    bool empty(){
        if(s.empty()){
            return 1;
        }
        return 0;
    }
};

int main(){

    min_stack s;
    s.push(-5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(-10);
    
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.getMin()<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}