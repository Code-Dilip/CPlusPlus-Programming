#include<iostream>
using namespace std;

void input_arr(int arr[],int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    cout<<endl;

    if(n==1){
        cout<<"Array length > 1 !"<<endl;
        return 0;
    }
    int arr[n+1];
    arr[n] = -1;
    input_arr(arr,n);

    int max_term = -1;
    int no_rb = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>max_term && arr[i]>arr[i+1]){
            no_rb += 1;
        }
        max_term = max(max_term,arr[i]);
    }

    cout<<"The number of record breakers is "<<no_rb<<" ."<<endl;
    return 0;
}