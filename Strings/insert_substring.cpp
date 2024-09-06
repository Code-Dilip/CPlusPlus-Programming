#include<iostream>
#include<string>

using namespace std;

int main(){
    string str,sub_string,sub_string_2;
    int idx;
    cout<<"\nenter the main string: ";
    getline(cin,str);
    cout<<"The string entered is "<<str<<endl;

    cout<<"\nenter the sub string to insert into the main node: ";
    getline(cin,sub_string);
    cout<<"enter the index to insert sub string: ";
    cin>>idx;
    str.insert(idx,sub_string);

    cout<<"\nThe main string after insertion of sub string is "<<str<<endl;
    
    sub_string.clear();
    cout<<"\nenter the sub string to find in the main string: ";
    getline(cin,sub_string_2);
    idx = str.find(sub_string_2);
    cout<<"The substring is at #"<<idx<<" position of the main string. "<<endl;

    cout<<endl;
    return 0;
}