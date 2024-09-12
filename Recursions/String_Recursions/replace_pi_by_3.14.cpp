#include<iostream>
#include<string>

using namespace std;

void replacePi(string str){
    if(!str.length()){
        return ;
    }
    if((str[0]=='p' || str[0]=='P')&&(str[1]=='i' || str[1]=='I')){
        cout<<"3.14";
        replacePi(str.substr(2));
    }
    else{
        cout<<str[0];
        replacePi(str.substr(1));
    }
}

int main(){
    string str;
    cout<<"\nenter a string: ";
    getline(cin,str);
    cout<<"The string entered is "<<str<<endl;
    cout<<"The string after replacing 'pi' by '3.14' is ";
    replacePi(str);
    cout<<endl;
    cout<<endl;
    return 0;
}