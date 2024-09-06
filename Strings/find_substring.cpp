#include<iostream>
#include<string>

using namespace std;

int main(){
    string str,sub_string,sub_string_2;
    int idx;
    cout<<"\nenter the main string: ";
    getline(cin,str);
    cout<<"The string entered is "<<str<<endl;

    cout<<"\nenter the sub string to find in the main string: ";
    getline(cin,sub_string);
    idx = str.find(sub_string);
    if(idx == -1){
        cout<<"The substring is not present in the main string!"<<endl;
    }
    else{
        cout<<"The substring is at #"<<idx<<" position of the main string. "<<endl;
    }

    cout<<endl;
    return 0;
}