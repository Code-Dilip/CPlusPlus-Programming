#include<iostream>
#include<vector>
using namespace std;

void print_all_subarray(vector <int> arr){
    int n = arr.size();
    for(int st=0;st<n;st++){
        for(int end=st;end<n;end++){
            for(int i=st;i<=end;i++){
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector <int> arr = {1,2,3,4,5};
    print_all_subarray(arr);
    return 0;
}