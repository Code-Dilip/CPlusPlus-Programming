#include<iostream>

using namespace std;

int gcd(int a,int b){
    int max_no = max(a,b);
    int min_no = min(a,b);
    int rem = 0;
    while(min_no){
        rem = max_no % min_no;
        max_no = min_no;
        min_no = rem;
    }
    return max_no;
}

int main(){
    int n,m;
    cout<<"\nenter a first number: ";
    cin>>n;
    cout<<"enter a second number: ";
    cin>>m;
    cout<<"GCD of "<<n<<" and "<<m<<" is "<<gcd(n,m)<<endl;
    cout<<endl;
    return 0;
}