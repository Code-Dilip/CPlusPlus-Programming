#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> NGE_II(vector <int> nums){
    int n = nums.size();
    vector <int> ans(n,0);
    stack <int> s;

    for(int i=2*n-1;i>=0;i--){
        while(s.size()>0 && nums[s.top()]<=nums[i%n]){
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = nums[s.top()];
        }
        s.push(i%n);
    }
    return ans;
}

int main(){
    vector <int> arr = {1,2,3,4,3};
    vector <int> ans = NGE_II(arr);
    for(int val:ans){
        cout<<val<<" ";
    }
    return 0;
}