#include<iostream>

using namespace std;

void input_arr(int *arr,int n){
    cout<<"\nenter the array elements: \n";
    for(int i=0;i<n;i++){
        cin>>*(arr+i);
    }
    cout<<endl;
}

void print_arr(int *arr,int n){
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
    cout<<" ]\n";
}

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[r]);
    return i;
}


void quick_sort(int arr[],int l,int r){
    if(l<r){
        int pi = partition(arr,l,r);

        quick_sort(arr,l,pi-1);
        quick_sort(arr,pi+1,r);
    }
}

int main(){
    int n;
    cout<<"\nenter the size of the array: ";
    cin>>n;
    int *arr = new int[n];
    input_arr(arr,n);
    cout<<"\nArray before sorting is ";
    print_arr(arr,n);

    quick_sort(arr,0,n-1);
    cout<<"Array after quick sort is ";
    print_arr(arr,n);

    return 0;
}