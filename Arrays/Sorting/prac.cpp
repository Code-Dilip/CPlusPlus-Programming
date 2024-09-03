#include<iostream>
using namespace std;

void input_arr(int arr[],int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void print_arr(int arr[],int n){
    cout<<"[ ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"]."<<endl;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int arr[],int n){
    if(n<=1){
        return;
    }
    int j,curr_ele;
    for(int i=1;i<n;i++){
        j = i-1;
        curr_ele = arr[i];
        while (j>=0 && curr_ele < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr_ele;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<endl;
    if(n<=0){
        return 0;
    }
    int arr[n];

    input_arr(arr,n);
    cout<<"The array before sorting: ";
    print_arr(arr,n);
    insertion_sort(arr,n);
    cout<<"The array after insertion sort: ";
    print_arr(arr,n);

    return 0;
}