#include<iostream>
#include<string>

using namespace std;

void convert_to_lowercase(string str){
    int n = str.size();
    for(int i=0;i<n;i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i] += 32;
        }
    }
    cout<<str<<endl;
}

void convert_to_uppercase(string str){
    int n = str.size();
    for(int i=0;i<n;i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i] -= 32;
        }
    }
    cout<<str<<endl;
}

int main(){
    string str;
    cout<<"\nenter a string: ";
    getline(cin,str);
    cout<<"\nstring in lower case: ";
    convert_to_lowercase(str);
    cout<<"string in upper case: ";
    convert_to_uppercase(str);

    cout<<endl;
    return 0;
}