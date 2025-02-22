#include<iostream>
#include<set>
#include<vector>
using namespace std;


void combination_sum(vector<int> &arr, vector <vector <int>> &ans, vector <int> &combin, int tar, int idx){
    if (idx == arr.size() && tar<0)
    {
        return ;
    }
    if(tar==0){
        ans.push_back(combin);
        return ;
    }
    combin.push_back(arr[idx]);
    combination_sum(arr,ans,combin,tar-arr[idx],idx+1); //single inclusion
    combination_sum(arr,ans,combin,tar-arr[idx],idx); //multiple inclusion
    combin.pop_back(); //back track
    combination_sum(arr,ans,combin,tar-arr[idx],idx+1); //exclusion
}

int main(){
    vector <int> arr = {2,3,5};
    vector <int> combin;
    vector <vector <int>> ans;
    combination_sum(arr,ans,combin,8,0);
    for(vector <int> combin: ans){
        for(int val: combin){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}