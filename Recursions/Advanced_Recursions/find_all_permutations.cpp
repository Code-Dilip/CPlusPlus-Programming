#include<iostream>
#include<string>

using namespace std;

void permutations(string str,string ans){
    if(!str.length()){
        cout<<ans<<endl;
        return ;
    }
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        string ros = str.substr(0,i)+str.substr(i+1);
        permutations(ros,ans+ch);
    }
}

int main(){
    string str;
    cout<<"\nenter a string: ";
    getline(cin,str);
    cout<<"All the permutations of the string "<<str<<" are: "<<endl;
    permutations(str,"");
    cout<<endl;
    return 0;
}