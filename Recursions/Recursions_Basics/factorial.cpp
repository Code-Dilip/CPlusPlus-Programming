#include<iostream>

using namespace std;

int fact(int n){
    if(!n){
        return 1;
    }
    return (n*fact(n-1));
}

int main(){
    int n;
    cout<<"\nenter a number to find factorial of it: ";
    cin>>n;
    cout<<"factorial of "<<n<<" is "<<fact(n)<<endl;
    cout<<endl;
    return 0;
}