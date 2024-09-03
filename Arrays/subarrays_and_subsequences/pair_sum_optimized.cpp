#include<iostream>
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

void insertion_sort(int arr[],int n){
    if(n==1){
        return ;
    }
    int j;
    int curr_element = 0;
    for(int i=1;i<n;i++){
        j = i-1;
        curr_element = arr[i];
        while(curr_element < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr_element;
    }
}

bool pair_sum(int arr[],int n,int sum){
    int st=0,en = n-1;
    while(st<en){
        if((arr[st]+arr[en])==sum){
            cout<<arr[st]<<"+"<<arr[en]<<"="<<sum<<endl;
            return true;
        }
        else if((arr[st]+arr[en])<sum){
            st ++;
        }
        else{
            en --;
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
    cout<<"Array before sorting: ";
    print_arr(arr,n);
    insertion_sort(arr,n);
    cout<<"Array after sorting: ";
    print_arr(arr,n);

    int sum;
    cout<<"Enter the target sum: ";
    cin>>sum;

    cout<<pair_sum(arr,n,sum)<<endl;
    cout<<endl;
    return 0;
}