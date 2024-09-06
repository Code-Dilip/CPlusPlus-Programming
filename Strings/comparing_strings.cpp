#include<iostream>
#include<string>

using namespace std;

void check(string str1,string str2){
    if(!str1.compare(str2)){
        cout<<" Both the strings are equal!"<<endl;
    }
    else{
        cout<<" The stings are not equal!"<<endl;
    }
}

int main(){
    string str1,str2;
    cout<<"\n enter the first string: ";
    getline(cin,str1);
    cout<<" enter the second string: ";
    getline(cin,str2);
    
    cout<<" str1.compare(str2): "<<str1.compare(str2)<<endl;
    check(str1,str2);

    cout<<endl;
    return 0;
}