#include<iostream>
#include<vector>
#include<set>
using namespace std;

set <vector<int>> s;

void getCombinations(vector<int> &arr, vector<int>&combination, vector<vector<int>>&ans, int tar, int idx){
    if(idx==arr.size() || tar<0){
        return;
    }
    if(tar==0){
        if(s.find(combination) == s.end()){
            for(int val: combination){
                cout<<val<<" ";
            }
            cout<<endl;
            ans.push_back(combination);
            s.insert(combination);
        }
        return ;
    }

    combination.push_back(arr[idx]);
    getCombinations(arr,combination,ans,tar-arr[idx],idx+1); //single inclusion
    getCombinations(arr,combination,ans,tar-arr[idx],idx); //multiple inclusion
    combination.pop_back(); //back track
    getCombinations(arr,combination,ans,tar,idx+1); //exclusion
}

void combination_sum(vector <int> &arr, int tar,vector <vector <int>> ans){
    vector <int> combination;
    getCombinations(arr,combination,ans,tar,0);
}

int main(){
    
    vector <int> arr = {2,3,5};
    int tar = 8;
    vector <vector<int>> ans;
    combination_sum(arr,tar,ans);
    for(vector <int> combi: ans){
        for(int val: combi){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}