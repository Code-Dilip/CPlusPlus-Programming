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

int maximum_subarray_sum(int arr[],int n){
    int cumm_sum[n],curr_sum = 0,max_sum = INT_MIN;
    for(int i=0;i<n;i++){
        curr_sum += arr[i];
        cumm_sum[i] = curr_sum;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            curr_sum = cumm_sum[i] - cumm_sum[j];
            max_sum = max(max_sum,curr_sum);
        }
    }
    return max_sum;
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

    cout<<maximum_subarray_sum(arr,n)<<endl;
    cout<<endl;
    return 0;
}