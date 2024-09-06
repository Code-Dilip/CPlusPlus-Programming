#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string str;
    cout<<"\nenter the main string: ";
    getline(cin,str);
    cout<<"The string entered is "<<str<<endl;

    sort(str.begin(),str.end());
    cout<<"The string after sorting is "<<str<<endl;

    cout<<endl;
    return 0;
}