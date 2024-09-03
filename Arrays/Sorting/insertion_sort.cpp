#include<iostream>
using namespace std;

void input_arr(int arr[],int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
}

void print_arr(int arr[],int n){
    cout<<"[ ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"] "<<endl;
}

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int current = arr[i];
        int j = i-1;
        while(arr[j]>current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<endl;
    int arr[n];

    input_arr(arr,n);
    cout<<"Array before sorting: ";
    print_arr(arr,n);
    insertion_sort(arr,n);
    cout<<"Array after insertion sort: ";
    print_arr(arr,n);

    cout<<endl;
    return 0;
}