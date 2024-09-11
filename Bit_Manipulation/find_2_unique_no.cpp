#include<iostream>

using namespace std;

int get_bit(int n,int pos){
    return !(n&(1<<pos));
}

void unique_no(int arr[],int n){
    int xor_sum = 0;
    for(int i=0;i<n;i++){
        xor_sum ^= arr[i];
    }
    int temp_xor_sum = xor_sum;
    int pos = 0,set_bit = 0;
    while(set_bit!=1){
        pos ++;
        set_bit = temp_xor_sum & 1;
        temp_xor_sum >>= 1;
    }
    int new_xor_sum = 0;
    for(int i=0;i<n;i++){
        if(get_bit(arr[i],pos-1)){
            new_xor_sum ^= arr[i];
        }
    }
    cout<<new_xor_sum<<endl;
    cout<<(new_xor_sum^xor_sum)<<endl;
}

int main(){
    int arr[] = {2,3,4,5,7,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<endl;
    unique_no(arr,n);
    cout<<endl;
    return 0;
}