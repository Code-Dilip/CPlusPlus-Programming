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

int kadane(int arr[],int n){
    int max_sum = INT_MIN,curr_sum = 0;
    for(int i=0;i<n;i++){
        curr_sum += arr[i];
        if(curr_sum < 0){
            curr_sum = 0;
        }
        max_sum = max(max_sum,curr_sum);
    }
    return max_sum;
}

int max_circular_subarray_sum(int arr[],int n){
    int total_sum = 0 ,wrap_sum = 0,non_wrap_sum = 0;
    non_wrap_sum = kadane(arr,n);
    for(int i=0;i<n;i++){
        total_sum += arr[i];
        arr[i] = -arr[i];
    }
    wrap_sum = total_sum + kadane(arr,n);
    return max(wrap_sum,non_wrap_sum);
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

    cout<<max_circular_subarray_sum(arr,n)<<endl;
    cout<<endl;
    return 0;
}