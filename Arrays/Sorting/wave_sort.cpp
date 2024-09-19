#include<iostream>

using namespace std;

void input_arr(int arr[],int n){
    cout<<"\nenter the elements in the array: \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
}

void print_arr(int arr[],int n){
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
    cout<<" ]"<<endl;
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void wave_sort(int arr[],int n){
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        if(arr[i]>arr[i+1] && i<=n-2){
            swap(arr[i],arr[i+1]);
        }
    }
}

int main(){
    int n;
    cout<<"\nenter the size of the array: ";
    cin>>n;
    int arr[n];
    input_arr(arr,n);
    cout<<"Array before sorting is ";
    print_arr(arr,n);

    wave_sort(arr,n);
    cout<<"Array after wave sort is ";
    print_arr(arr,n);
    cout<<endl;
    return 0;
}