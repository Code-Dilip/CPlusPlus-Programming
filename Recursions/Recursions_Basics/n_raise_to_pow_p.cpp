#include<iostream>

using namespace std;

int n_pow_p(int n,int pow){
    if(!pow){
        return 1;
    }
    return (n*n_pow_p(n,pow-1));
}

int main(){
    int n,p;
    cout<<"\nenter the value for base n: ";
    cin>>n;
    cout<<"enter the power for the base n: ";
    cin>>p;
    cout<<n<<"^"<<p<<"="<<n_pow_p(n,p)<<endl;
    return 0;
}