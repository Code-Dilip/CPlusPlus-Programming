#include<iostream>
#include<vector>
using namespace std;

void getSubsets(vector <int> &arr,vector <int> &ans, int i,vector <vector <int>> &allSubsets){
    if(i == arr.size()){
        allSubsets.push_back({ans});
        return ;
    }
    
    //include 
    ans.push_back(arr[i]);
    getSubsets(arr,ans,i+1,allSubsets);

    ans.pop_back(); //bakctrack

    //exclude
    int idx = i+1;
    while(idx<arr.size() && arr[idx]==arr[idx-1]){
        idx++;
    }
    getSubsets(arr,ans,idx,allSubsets);
}

int main(){
    vector <int> arr = {1,2,2};
    vector <int> ans;
    vector <vector <int> > allsubsets;

    getSubsets(arr,ans,0,allsubsets);

    for(vector <int> subset:allsubsets){
        for(int val:subset){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}