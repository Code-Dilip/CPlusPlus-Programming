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

int no_of_record_breaking_days(int arr[],int n){
    int count = 0,mx=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>mx && arr[i]>arr[i+1]){
            count ++;
        }
        mx = max(mx,arr[i]);
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    if(n<2){
        return 0;
    }
    cout<<endl;
    int arr[n+1];
    arr[n] = -1;
    
    input_arr(arr,n);

    cout<<no_of_record_breaking_days(arr,n)<<endl;
    return 0;
}