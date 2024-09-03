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
    cout<<endl;
    int arr[n];
    input_arr(arr,n);

    int sum;
    for(int i=0;i<n;i++){
        sum = 0;
        cout<<"Subarray: [ ";
        for(int j=i;j<n;j++){
            sum += arr[j];
            cout<<arr[j]<<" ";
        }
        cout<<" ] Sum: "<<sum<<endl;
    }

    cout<<endl;
    return 0;
}