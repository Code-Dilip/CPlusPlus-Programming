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

void subarray_equal_to_a_given_sum(int arr[],int n,int sum){
    int st,en,i,j,current_sum = 0;
    st = en = -1;
    i = j = 0;
    while(j<n && (current_sum+arr[j]) <= sum){
        current_sum += arr[j];
        j++;
    }
    if(current_sum == sum){
        st = i;
        en = j-1;
        cout<<"Starting Index: "<<st<<"  Ending Index: "<<en<<endl;
        return ;
    }
    while(j<n){
        current_sum += arr[j];
        while(current_sum > sum){
            current_sum -= arr[i];
            i++;
        }
        if(current_sum == sum){
            st = i;
            en = j;
            break;
        }
        j++;
    }
    cout<<"Starting Index: "<<st<<"  Ending Index: "<<en<<endl;
}

int main(){
    int n,sum;
    cout<<"Enter the size of the array: ";
    cin>>n;
    if(n<=0){
        return 0;
    }
    cout<<endl;
    int arr[n];
    input_arr(arr,n);

    cout<<"Enter the sum:";
    cin>>sum;
    cout<<endl;

    subarray_equal_to_a_given_sum(arr,n,sum);
    cout<<endl;
    
    return 0;
}