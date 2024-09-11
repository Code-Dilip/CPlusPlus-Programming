#include<iostream>

using namespace std;

int getBit(int n,int pos){
    return ((n&(1<<pos))!=0);
}

int setBit(int n,int pos){
    return (n|(1<<pos));
}

int clearBit(int n,int pos){
    return (n&(~(1<<pos)));
}

int updateBit(int n,int pos,int value){
    n = (n&(~(1<<n)));
    return (n|(value<<pos));
}

bool powof2(int n){
    return (!(n&(n-1)));
}

int count_1s(int n){
    int count = 0;
    while(n){
        count++;
        n &= (n-1);
    }
    return count;
}

void subsets(int arr[],int n){
    for(int i=0;i<(1<<n);i++){
        cout<<"{ ";
        for(int j=0;j<n;j++){
            if((i&(1<<j))){
                cout<<arr[j]<<" ";
            }
        }
        cout<<"}"<<endl;
    }
}

int main(){
    int  arr[]={1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    subsets(arr,n);
    cout<<endl; 
    return 0;
}