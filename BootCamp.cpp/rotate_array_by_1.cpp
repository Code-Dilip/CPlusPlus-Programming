#include<iostream>
#include<vector>

using namespace std;

void rotate_by_1_pos(int arr[], int n){
    int last_ele = arr[n-1];
    
    for(int i=n-1;i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = last_ele;
}

void rotate_by_n_pos(int arr[], int n,int k){
   int d = d%n;
   int temp_arr[d];

   for(int i=0;i<d;i++){
    temp_arr[i] = arr[n-d+i];
   }
   for(int i=n-1;i>=d;i--){
    arr[i] = arr[i-d];
   }
   for(int i=0;i<d;i++){
    arr[i] = temp_arr[i];
   }
}


int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5, k=3;

    rotate_by_n_pos(arr,n,3);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
    
}