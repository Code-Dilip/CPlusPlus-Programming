#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class min_stack{
    public:
    stack <pair<int,int>> s;
    void push(int val){
        if(s.empty()){
            s.push({val,val});
        }
        else{
            int min_val = min(val,s.top().second);
            s.push({val,min_val});
        }
    }

    void pop(){
        s.pop();
    }

    int top(){
        return s.top().first;
    }

    int getMin(){
        return s.top().second;
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