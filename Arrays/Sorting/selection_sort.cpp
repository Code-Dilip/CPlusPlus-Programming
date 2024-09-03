#include<iostream>
using namespace std;


void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[],int n){
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

void print_array(int arr[],int n){
    cout<<"[ ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    cout<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
    
    cout<<"Array before sorting: ";
    print_array(arr,n);
    selection_sort(arr,n);
    cout<<"Array after selection sort: ";
    print_array(arr,n);
    
    
    return 0;
}