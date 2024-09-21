#include<iostream>

using namespace std;

void input_arr(int arr[],int n){
    cout<<"\nenter the array elements!\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
}

void print_arr(int arr[],int n){
    cout<<"\n[";
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
    cout<<" ]\n";
}

int count_inversions(int arr[],int n){
    int inv = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                inv ++;
            }
        }
    }
    return inv;
}

int main(){
    int n;
    cout<<"\nenter the size of the array: ";
    cin>>n;
    int arr[n];
    input_arr(arr,n);
    cout<<"\nThe array is ";
    print_arr(arr,n);
    cout<<"\nThe no. of inversions in the array is "<<count_inversions(arr,n)<<endl;
    cout<<endl;
    return 0;
}