#include<iostream>
#include<string>

using namespace std;

void reverse(string str){
    if(!str.length()){
        return ;
    }
    reverse(str.substr(1));
    cout<<str[0];
}

int main(){
    string str;
    cout<<"\nenter a string to reverse it: ";
    getline(cin,str);
    cout<<"\nThe string is "<<str<<endl;
    cout<<"The reversed string is ";
    reverse(str);
    cout<<endl;
    return 0;
}