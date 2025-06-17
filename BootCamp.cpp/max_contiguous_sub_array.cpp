#include<iostream>

using namespace std;

void count_max(int arr[], int n){

    int max_count = 1;
    int curr_count = 1;
    for(int i=0;i<n;i++){
        if((arr[i]%2==0 && arr[i+1]%2!=0) || (arr[i]%2!=0 && arr[i+1]%2==0)){
            curr_count ++;
            max_count = max(max_count, curr_count);
        }
        else{
            curr_count = 1;
        }
    }
    cout<<max_count<<endl;
}

int main(){

    int arr[] = {2,4,6,7,8};
    int n = 5;

    count_max(arr, n);
    return 0;
}