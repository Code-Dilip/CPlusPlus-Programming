#include<iostream>

using namespace std;

int no_of_dividers(int n,int a,int b){
    return ((n/a)+(n/b))-(n/(a+b));
}

int main(){
    int a,b,n;
    cout<<"\nenter the divident: ";
    cin>>n;
    cout<<"\nenter the first divisor: ";
    cin>>a;
    cout<<"enter the second divisor: ";
    cin>>b;
    cout<<no_of_dividers(n,a,b)<<endl;
    cout<<endl;
    return 0;
}