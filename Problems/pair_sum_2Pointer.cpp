#include<iostream>
#include<vector>
using namespace std;


int pair_sum_2pointer(vector <int> arr,int target){
    int n = arr.size();
    vector <int> arr;
    int i=0, j=n-1;
    
    while(i<j){
        if((arr[i]+arr[j])<target){
            i++;
        }
        elseif((arr[i]+arr[j])>arget){
            j--;
        }
     else {
        
     }
}
int main(){

    return 0;
}