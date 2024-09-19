#include<iostream>
#include<climits>

using namespace std;

void input_arr(int arr[],int n){
    cout<<"\nenter the array elements:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
}

void count_sort(int arr[],int n){
    int max_ele = INT_MIN;
    for(int i=0;i<n;i++){
        max_ele = max(max_ele,arr[i]);
    }
    int count[100] = {0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=max_ele;i++){
        count[i] += count[i-1];
    }

    int output_arr[n];
    for(int i=0;i<n;i++){
        output_arr[--count[arr[i]]] = arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i] = output_arr[i];
    }
}

void print_arr(int arr[],int n){
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
    cout<<" ]\n";
}

int main(){
    int n;
    cout<<"\nenter the size of the array: ";
    cin>>n;
    int arr[n];
    input_arr(arr,n);
    cout<<"Array before sorting is ";
    print_arr(arr,n);
    count_sort(arr,n);
    cout<<"Array after count sort is ";
    print_arr(arr,n);
    cout<<endl;
    return 0;
}