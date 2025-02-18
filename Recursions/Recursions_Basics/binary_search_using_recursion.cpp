#include<iostream>
#include<vector>
using namespace std;

int binary_search(vector<int> arr, int key, int start, int end){
    if(start>end){
        return -1;
    }
    int mid = (start+end)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]>key){
        return binary_search(arr,key,start,mid-1);
    }
    else{
        return binary_search(arr,key,mid+1,end);
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int key = 4;
    int i = binary_search(arr,key,0,4);
    if(i==-1){
        cout<<"The search element "<<key<<" is not present! "<<endl;
    }
    else{
        cout<<"The search element "<<key<<" is present at #"<<i<<" index!"<<endl;
    }
    return 0;
}