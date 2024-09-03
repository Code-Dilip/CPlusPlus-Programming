#include<iostream>
using namespace std;

void fib(int n){
    int t1=0,t2=1,next_term;
    for(int i=0;i<n;i++){
        cout<<t1<<" ";
        next_term = t1+t2;
        t1 = t2;
        t2 = next_term;
    }
}

int main(){
    int n;
    cin>>n;
    fib(n);
    return 0;
}