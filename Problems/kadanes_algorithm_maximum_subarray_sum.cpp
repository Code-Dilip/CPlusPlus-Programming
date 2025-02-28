#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int max_subarray_sum(vector <int> arr){
    int n = arr.size();
    int curr_sum=0, max_sum=INT_MIN;
    
    for(int i=0;i<n;i++){
        curr_sum += arr[i];
        max_sum = max(max_sum,curr_sum);
        if(curr_sum<0){
            curr_sum = 0;
        }
    }
    return max_sum;
}
int main(){
    vector<int> arr = {1,2,3,4,5};
    cout<<max_subarray_sum(arr)<<endl;
    return 0;
}