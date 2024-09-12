#include<iostream>
#include<string>

using namespace std;

string moveAllX(string str){
    if(!str.length()){
        return "";
    }
    char ch = str[0];
    string ans = moveAllX(str.substr(1));
    if(ch == 'x' || ch == 'X'){
        return (ans+ch);
    }
    return (ch+ans);
}

int main(){
    string str;
    cout<<"\nenter a string with characters x in between: ";
    getline(cin,str);
    cout<<"The string entered is "<<str<<endl;
    cout<<"The string after moving all the X at end is "<<moveAllX(str)<<endl;
    cout<<endl;
    return 0;
}