#include<iostream>

using namespace std;

int fibbo(int n){
    if(n==0 || n==1){
        return n;
    }
    return (fibbo(n-1)+fibbo(n-2));
}

int main(){
    int n;
    cout<<"\nenter the number to find first n fibonacci series: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<fibbo(i)<<" ";
    }
    cout<<endl;
    return 0;
}