#include<iostream>

using namespace std;

void input_arr(int *arr,int n){
    cout<<"\nenter the array elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>*(arr+i);
    }
    cout<<endl;
}

void print_arr(int *arr,int n){
    cout<<"\nThe array is [ ";
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<"] .";
}

bool is_sort(int *arr,int n){
    if(n==1){
        return true;
    }
    return (*(arr+0)<*(arr+1) && is_sort(arr+1,n-1));
}

int main(){
    int n;
    cout<<"\nenter the size of the array: ";
    cin>>n;
    int arr[n];
    input_arr(arr,n);
    print_arr(arr,n);

    if(is_sort(arr,n)){
        cout<<"The given array is sorted! "<<endl;
    }
    else{
        cout<<"The given array is not sorted! "<<endl;
    }
    return 0;
}