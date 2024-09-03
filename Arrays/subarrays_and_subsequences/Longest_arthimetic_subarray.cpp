#include<iostream>
using namespace std;

void input_arr(int arr[],int n){
    cout<<"enter the elements of array! "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"\nenter the size of the array: ";
    cin>>n;
    if(n<2){
        cout<<"Array length should be greater than 2!"<<endl;
        return 0;
    }
    int arr[n];
    input_arr(arr,n);

    int pd = arr[1]-arr[0];
    int curr_length,max_length;
    curr_length = max_length = 2;
    int j=2;

    while(j<n){
        if(pd == arr[j]-arr[j-1]){
            curr_length += 1;
        }
        else{
            curr_length = 2;
        }
        pd = arr[j]-arr[j-1];
        max_length = max(max_length,curr_length);
        j ++;
    }
    cout<<"The length of the longest arthimetic subarray is "<<max_length<<" ."<<endl;
    return 0;
}