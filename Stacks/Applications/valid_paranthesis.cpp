#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool valid_paranthesis(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            s.push(str[i]);
        }
        else{
            if(s.size()==0){
                return false;
            }
            char a=s.top(), b=str[i];
            if((a=='('&&b==')')||(a=='['&&b==']')||(a=='{'&&b=='}')){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    return (s.size()==0);
}

int main(){
    string str;
    cout<<"enter string parenthesis: ";
    cin>>str;

    if(valid_paranthesis(str)){
        cout<<"Valid parenthesis!"<<endl;
    }
    else{
        cout<<"InValid parenthesis!"<<endl;
    }
    return 0;
}