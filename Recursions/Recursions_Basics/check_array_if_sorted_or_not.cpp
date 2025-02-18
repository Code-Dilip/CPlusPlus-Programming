#include<iostream>
#include<vector>
using namespace std;

bool is_Sorted(vector <int> arr,int n){
    if(n==0 || n==1){
        return true;
    }
    return (arr[n-2]<=arr[n-1]) && is_Sorted(arr,n-1);
}

int main(){
    vector <int> arr = {2,1,3,4};
    int s = is_Sorted(arr,arr.size());
    if(s){
        cout<<"The array is Sorted! "<<endl;
    }
    else{
        cout<<"The array is not sorted! "<<endl;
    }
    return 0;
}