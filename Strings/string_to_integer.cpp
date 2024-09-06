#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    cout<<"\nenter the numeric string: ";
    getline(cin,str);
    cout<<"The string entered is "<<str<<endl;
    
    int num = stoi(str);
    cout<<"\nNumber is "<<num<<endl;

    cout<<"\nenter a number to convert it to string: ";
    cin>>num;
    cout<<"Numeric string is "<<to_string(num)<<endl;

    cout<<endl;
    return 0;
}