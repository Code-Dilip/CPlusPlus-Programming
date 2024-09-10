#include<iostream>

using namespace std;

int getBit(int n,int pos){
    return ((n&(1<<pos))!=0);
}

int main(){
    int n = 5,pos=2;
    cout<<endl;
    cout<<getBit(n,pos)<<endl;
    return 0;
}