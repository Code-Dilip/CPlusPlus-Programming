#include<iostream>

using namespace std;

int unique_no(int arr[],int n){
    int xor_sum=0;
    for(int i=0;i<n;i++){
        xor_sum ^= arr[i];
    }
    return xor_sum;
}

int main(){
    int arr[] = {2,4,6,3,4,2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<endl;
    cout<<unique_no(arr,n)<<endl;
    cout<<endl;
    return 0;
}