#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maximum_sum_subarray(vector<int> arr){
    int n = arr.size();
    int max_sum = INT_MIN;
    for(int st=0;st<n;st++){
        int curr_sum = 0;
        for(int end=st;end<n;end++){
            curr_sum += arr[end];
            max_sum = max(max_sum,curr_sum);
        }
    }
    return max_sum;
}

int main(){
    vector <int> arr = {1,2,3,4,5};
    cout<<maximum_sum_subarray(arr)<<endl;
    return 0;
}