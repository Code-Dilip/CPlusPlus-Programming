#include<iostream>

using namespace std;

int count_no_ones(int n){
    int count = 0;
    while(n){
        count ++;
        n = (n & (n-1));
    }
}

int main(){
    int n = 15;
    cout<<endl;
    cout<<count_no_ones(n)<<endl;
    cout<<endl;
    return 0;
}