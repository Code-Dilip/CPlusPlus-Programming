#include<iostream>
#include<string>

using namespace std;

string removeDuplicates(string str){
    if(!str.length()){
        return "";
    }
    char ch = str[0];
    string ans = removeDuplicates(str.substr(1));
    if(ch == ans[0]){
        return ans;
    }
    return (ch+ans);
}

int main(){
    string str;
    cout<<"\nenter a sting with duplication: ";
    getline(cin,str);
    cout<<"The string entered is "<<str<<endl;
    cout<<"The string after removing duplications is "<<removeDuplicates(str)<<endl;
    cout<<endl;
    return 0;
}