#include<iostream>
#include<vector>
#include<string>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printPermutations(vector <string> &s,vector<string> &ans, int idx){
    if(idx == s.size()){
        ans = s;
        for(string val:ans){
            cout<<val<<" ";
        }
        cout<<endl;
        return ;
    }
    for(int i=idx;i<s.size();i++){
        swap(s[i],s[idx]);
        printPermutations(s,ans,idx+1);
        swap(s[i],s[idx]);
    }
}

int main(){
    vector <string> s = {"abc"};
    vector <string> ans ;
    printPermutations(s,ans,0);
    cout<<endl;
    return 0;
}