#include<iostream>

using namespace std;

bool getBit(int n,int pos){
    return (n&(1<<pos))!=0;
}

int setBit(int n,int pos){
    return (n|(1<<pos));
}

int clearBit(int n,int pos){
    return (n&(~(1<<pos)));
}

int main(){
    int n=5,pos=2;
    cout<<endl;
    cout<<getBit(n,pos)<<endl;
    cout<<setBit(n,pos)<<endl;
    n = setBit(n,pos);
    cout<<getBit(n,pos)<<endl;
    n = clearBit(n,pos);
    cout<<getBit(n,pos)<<endl;
    return 0;
}