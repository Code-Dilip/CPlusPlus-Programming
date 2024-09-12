#include<iostream>

using namespace std;

void inc(int n){
    if(!n){
        return;
    }
    inc(n-1);
    cout<<n<<" ";
}

void dec(int n){
    if(!n){
        return;
    }
    cout<<n<<" ";
    dec(n-1);
}

int main(){
    int n;
    cout<<"\nenter a integer: ";
    cin>>n;
    cout<<"\nIncreasing order of numbers till "<<n<<" is ";
    inc(n);
    cout<<"\nDecreasing order of numbers till "<<n<<" is ";
    dec(n);
    cout<<endl;
    return 0;
}