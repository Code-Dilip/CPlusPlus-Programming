#include<iostream>

using namespace std;

void subsets(int arr[],int n){
    for(int i=0;i<(1<<n);i++){
        cout<<"{ ";
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<"}"<<endl;
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<endl;
    subsets(arr,n);
    cout<<endl;
    return 0;
}