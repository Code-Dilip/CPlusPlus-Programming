#include<iostream>

using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void DNF_Sort(int arr[],int n){
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low ++;
            mid ++;
        }
        else if(arr[mid] == 1){
            mid ++;
        }
        else if(arr[mid] == 2){
            swap(arr[mid],arr[high]);
            high --;
        }
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
    int arr[] = {1,1,2,0,0,1,2,2,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"\nThe array before sorting is ";
    print_arr(arr,n);

    DNF_Sort(arr,n);
    cout<<"\nThe array after sorgint is ";
    print_arr(arr,n);
    return 0;
}