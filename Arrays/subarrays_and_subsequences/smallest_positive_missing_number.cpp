#include<iostream>
using namespace std;

const int N = 1e6+2;

void input_arr(int arr[],int n){
    cout<<"Enter the array elements:"<<endl;
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
    cout<<"]."<<endl;
}

int smallest_positive_missing_no(int arr[],int n){
    bool check[N];
    for(int i=0;i<N;i++){
        check[i] = false;
    }
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            check[arr[i]] = true;
        }
    }
    for(int i=0;i<N;i++){
        if(check[i] == false){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    if(n<=0){
        return 0;
    }
    cout<<endl;
    int arr[n];
    input_arr(arr,n);

    cout<<smallest_positive_missing_no(arr,n)<<endl;
    cout<<endl;
    return 0;

}