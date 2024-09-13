#include<iostream>

using namespace std;

int pairFriends(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    return (pairFriends(n-1)+pairFriends(n-2)*(n-1));
}

int main(){
    int n;
    cout<<"\nenter the number of friends: ";
    cin>>n;
    cout<<"The total number of ways to pair is "<<pairFriends(n)<<" ."<<endl;
    cout<<endl;
    return 0;
}