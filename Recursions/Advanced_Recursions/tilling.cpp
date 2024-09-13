#include<iostream>

using namespace std;

int tillingCount(int n){
    if(n==0 || n==1){
        return n;
    }
    return tillingCount(n-1)+tillingCount(n-2);
}

int main(){
    int n;
    cout<<"\nenter the number of tails to be laid: ";
    cin>>n;
    cout<<"The total number of ways to place "<<n<<" tails is "<<tillingCount(n)<<endl;
    cout<<endl;
    return 0;
}