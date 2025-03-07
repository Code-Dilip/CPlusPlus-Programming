#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>&arr,int st,int end){
    int pivot = arr[end];
    int idx = st-1;
    for(int j=st;j<end;j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[idx],arr[j]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}


void quickSort(vector<int> &ans,int st,int end){
    
    if(st<end){
        int pivot_idx = partition(ans,st,end);

        quickSort(ans,st,pivot_idx-1); //Left half
        quickSort(ans,pivot_idx+1,end); //Right half
    }
}

int main(){
    vector <int> arr = {6,5,4,3,2,1};
    quickSort(arr,0,arr.size()-1);
    for(int val: arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}