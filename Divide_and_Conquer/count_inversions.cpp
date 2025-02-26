#include<iostream>
#include<vector>
using namespace std;


int merge(vector<int> &arr,int st,int mid,int end){
    vector<int> temp;
    int i = st,j = mid+1;
    int invertions = 0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            invertions += (mid-i)+1;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    for(i=0;i<temp.size();i++){
        arr[st+i] = temp[i];
    }
    return invertions;
}

int countInversions(vector<int> &arr,int st,int end){
    if(st<end){
        int mid = (st+(end-st)/2);

        int left_inversions = countInversions(arr,st,mid); // Left half
        int right_inversions = countInversions(arr,mid+1,end); // Right half

        int inversions = merge(arr,st,mid,end);

        return (inversions+left_inversions+right_inversions);
    }
    return 0;
}

int main(){
    vector<int> arr = {1,3,5,10,2,6,8,9};
    int total_inversions = countInversions(arr,0,arr.size()-1);
    cout<<"Total Inversions: "<<total_inversions<<endl;
    return 0;
}