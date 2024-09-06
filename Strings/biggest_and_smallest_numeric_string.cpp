#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string str;
    cout<<"\nenter the numeric string: ";
    getline(cin,str);
    
    sort(str.begin(),str.end(),greater<int>());
    cout<<"Biggest number: "<<str<<endl;
    sort(str.begin(),str.end());
    cout<<"Smallest number: "<<str<<endl;
    
    cout<<endl;
    return 0;
}