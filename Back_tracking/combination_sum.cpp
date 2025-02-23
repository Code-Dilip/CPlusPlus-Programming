#include<iostream>
#include<vector>
using namespace std;

void print_combinations(vector <int> &arr, vector <int> &combi, int tar , int idx){
    if(idx == arr.size() || tar<0){
        return ;
    }
    if(tar==0){
        for(int val: combi){
            cout<<val<<" ";
        }
        cout<<endl;
        return ;
    }

    combi.push_back(arr[idx]);
    print_combinations(arr,combi,tar-arr[idx],idx+1); //single inclusion
    print_combinations(arr,combi,tar-arr[idx],idx); //multiple inclusion
    combi.pop_back(); // back tracking
    print_combinations(arr,combi,tar,idx+1); //exclusion

}

int main(){
    vector <int> arr = {2,3,5};
    vector <int> combi;
    int tar = 8;
    print_combinations(arr,combi,tar,0);
    return 0;
}