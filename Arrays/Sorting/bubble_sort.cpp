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
    cout<<"]"<<endl;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[],int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
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
    bubble_sort(arr,n);
    cout<<"Array after bubble Sort: ";
    print_arr(arr,n);

    return 0;
}