#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int> &arr,int st,int mid,int end){
    int i=st,j=mid+1;
    vector <int> temp;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while (j<=end)
    {
        temp.push_back(arr[j]);
    }
    for(i=0;i<temp.size();i++){
        arr[i+st] = temp[i];
    }
}

void merge_sort(vector<int> &arr,int st,int end){
    if(st<end){
        int mid = st+((end-st)/2);
        
        merge_sort(arr,st,mid);
        merge_sort(arr,mid+1,end);

        merge(arr,st,mid,end);
    }
}


int main(){
    vector<int> arr = {6,5,4,3,2,1};
    merge_sort(arr,0,arr.size()-1);
    for(int val: arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}