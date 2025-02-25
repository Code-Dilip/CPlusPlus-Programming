#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrome(string s){
    string s_cpy = s;
    reverse(s_cpy.begin(),s_cpy.end());
    return (s==s_cpy);
}

void get_palindromes(string s,vector<vector<string>> &ans,vector<string>partitions){
    if(s.size()==0){
        ans.push_back(partitions);
        return;
    }
    for(int i=0;i<s.size();i++){
        string part = s.substr(0,i+1);
        if(isPalindrome(part)){
            partitions.push_back(part);
            get_palindromes(s.substr(i+1),ans,partitions);
            partitions.pop_back();
        }
    }
}

int main(){
    string s="abaabcaba";
    vector<vector<string>> ans;
    vector <string> partitions;
    get_palindromes(s,ans,partitions);
    for(vector<string> partition: ans){
        for(string str: partition){
            cout<<str;
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}