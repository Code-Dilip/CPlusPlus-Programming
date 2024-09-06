#include<iostream>
#include<string>

using namespace std;

int main(){
    string str1 ,str2;
    cout<<"\n enter the first string: ";
    getline(cin,str1);

    cout<<" enter the second string: ";
    getline(cin,str2);

    str1.append(str2);
    cout<<" str1.append(str2): ";
    cout<<str1;
    cout<<endl;
    cout<<"str1+str2: ";
    cout<<str1+str2<<endl;

    cout<<"\nCheck whether the string is empty or not!"<<endl;
    if(str1.empty()){
        cout<<"string 1 is empty!"<<endl;
    }
    else{
        cout<<"string 1 is not empty!"<<endl;
    }
    if(str2.empty()){
        cout<<"string 2 is empty!"<<endl;
    }
    else{
        cout<<"string 2 is not empty!"<<endl;
    }
    
    //.clear() clear's a string
    str1.clear();
    str2.clear();
    cout<<"Strings after clearing! "<<endl;
    if(str1.empty()){
        cout<<"string 1 is empty!"<<endl;
    }
    else{
        cout<<"string 1 is not empty!"<<endl;
    }
    if(str2.empty()){
        cout<<"string 2 is empty!"<<endl;
    }
    else{
        cout<<"string 2 is not empty!"<<endl;
    }

    cout<<endl;
    return 0;
}