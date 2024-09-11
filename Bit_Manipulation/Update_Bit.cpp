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

int updateBit(int n,int pos,bool value){
    n = (n&(~(1<<pos)));
    return (n|(value<<pos));
}

int main(){
    int n=5,pos=2,value=1;
    cout<<endl;
    cout<<getBit(n,pos)<<endl;
    cout<<setBit(n,pos)<<endl;
    n = setBit(n,pos);
    cout<<getBit(n,pos)<<endl;
    n = clearBit(n,pos);
    cout<<getBit(n,pos)<<endl;
    cout<<updateBit(n,pos,value)<<endl;
    return 0;
}