#include<iostream>
#include<string>

using namespace std;

void generateSubstrings(string str,string ans){
    if(!str.length()){
        cout<<ans<<endl;
        return ;
    }
    char ch = str[0];
    generateSubstrings(str.substr(1),ans);
    generateSubstrings(str.substr(1),ans+ch);
}

int main(){
    string str;
    cout<<"\nenter a string to generate substrings of it: ";
    getline(cin,str);
    cout<<"The string entered is "<<str<<endl;
    cout<<"The substrings of the string "<<str<<" are ";
    generateSubstrings(str,"");
    return 0;
}