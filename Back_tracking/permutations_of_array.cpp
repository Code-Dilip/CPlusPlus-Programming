#include<iostream>
#include<vector>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void getPermutations(vector <int> &nums, vector<vector<int>> &ans, int i){
    if(i == nums.size()){
        ans.push_back(nums);
        return ;
    }
    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        getPermutations(nums,ans,i+1); //inclusion
        swap(nums[i],nums[j]); //back_tracking
    }
}

vector< vector<int>> permutations(vector<int> nums){
    vector <vector<int>> ans;
    getPermutations(nums,ans,0);
    return ans;
}

int main(){
    vector <int> nums = {2,3,5};
    vector <vector<int>> ans = permutations(nums);

    for(vector <int> comb : ans){
        for(int val : comb){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}