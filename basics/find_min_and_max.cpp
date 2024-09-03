#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(!n){
        return 0;
    }
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max_term = INT16_MIN,min_term = INT16_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<min_term){
            min_term = arr[i];
        }
        else if(arr[i]>max_term){
            max_term = arr[i];
        }
    }

    cout<<" max_term: "<<max_term<<endl;
    cout<<" min_term: "<<min_term<<endl;

    return 0;
}