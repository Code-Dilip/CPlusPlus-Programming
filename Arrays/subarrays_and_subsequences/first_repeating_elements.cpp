#include<iostream>
#include<climits>
using namespace std;

const int N = 1e6+2;

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
    cout<<"]."<<endl;
}

int first_repeating_element(int arr[],int n){
    if(n==1){
        return 0;
    }
    int idx[N],min_idx = INT_MAX;
    for(int i=0;i<N;i++){
        idx[i] = -1;
    }
    for(int i=0;i<n;i++){
        if(idx[arr[i]]!=-1){
            min_idx = min(min_idx,idx[arr[i]]);
        }
        else{
            idx[arr[i]] = i;
        }
    }
    if(min_idx == INT_MAX){
        return -1;
    }
    return min_idx;
}

int main(){
    int n;
    cin>>n;
    cout<<endl;
    if(n<0){
        return 0;
    }
    int arr[n];
    input_arr(arr,n);

    cout<<first_repeating_element(arr,n)<<endl;
    return 0;
}