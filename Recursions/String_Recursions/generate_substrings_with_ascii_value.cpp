#include<iostream>
#include<string>

using namespace std;

void generateSubstrings(string str,string ans){
    if(!str.length()){
        cout<<ans<<endl;
        return ;
    }
    char ch = str[0];
    int code = ch;
    generateSubstrings(str.substr(1),ans);
    generateSubstrings(str.substr(1),ans+ch);
    generateSubstrings(str.substr(1),to_string(code));
}

int main(){
    string str;
    cout<<"\nenter a string: ";
    getline(cin,str);
    cout<<"The string entered is "<<str<<endl;
    cout<<"The substrings with ASCII value are ";
    generateSubstrings(str,"");
    cout<<endl;
    return 0;
}