#include<iostream>

using namespace std;

int getBit(int n,int pos){
    return !(n&(1<<pos));
}

int setBit(int n,int pos){
    return (n|(1<<pos));
}

int findUnique(int arr[],int n){
    int unique_no = 0;
    for(int i=0;i<64;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            if(getBit(arr[j],i)){
                sum++;
            }
        }
        if(!(sum%3)){
            unique_no = setBit(unique_no,i);
        }
    }
    return unique_no;
}

int main(){
    int arr[] = {1,2,3,8,3,2,1,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<endl;
    cout<<findUnique(arr,n)<<endl;
    cout<<endl;
    return 0;
}