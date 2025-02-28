#include<iostream>
#include<vector>
using namespace std;

vector <int> pair_sum(vector <int> nums, int target){
   int n = nums.size();
   vector <int> ans;
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(nums[i]+nums[j]==target){
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
   }
   return ans;
}

int main(){
    vector <int> nums = {1,2,2,2,3,4};
    int target = 7;
    vector <int> ans = pair_sum(nums,target);
    for(int val: ans){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}