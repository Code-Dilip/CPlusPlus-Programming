#include<iostream>
#include<string>

using namespace std;

int main(){
    string str1,sub_str;
    int idx,len;
    cout<<"\nenter the string: ";
    getline(cin,str1);
    cout<<"The string is "<<str1<<endl;

    cout<<"Lenght of the string using .lenght() is "<<str1.length()<<endl;
    cout<<"Lenght of the string using .size() is "<<str1.length()<<endl;

    cout<<"\nenter the starting index of the substring to erase it from main string: ";
    cin>>idx;
    cout<<"enter the length of the substring: ";
    cin>>len;
    str1.erase(idx,len);
    cout<<"string after erasing the substring is "<<str1<<endl;
    
    cout<<"\nenter a substring to insert in main string: ";
    getline(cin,sub_str);
    cout<<"enter index to insert at: ";
    cin>>idx;
    str1.insert(idx,sub_str);
    cout<<"The main string after inserting substring in it is "<<str1<<endl;

    cout<<endl;
    return 0;
}