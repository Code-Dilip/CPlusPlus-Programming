#include<iostream>
#include<climits>
using namespace std;

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

bool pair_sum(int arr[],int n,int sum){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((arr[i]+arr[j])==sum){
                cout<<arr[i]<<"+"<<arr[j]<<"="<<sum<<endl;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    if(n<=0){
        return 0;
    }
    cout<<endl;
    int arr[n];
    input_arr(arr,n);

    int sum;
    cout<<"Enter the target sum: ";
    cin>>sum;
    
    cout<<pair_sum(arr,n,sum)<<endl;
    cout<<endl;
    return 0;
}