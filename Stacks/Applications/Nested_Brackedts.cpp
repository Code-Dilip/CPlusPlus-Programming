#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isValid(string str){
    int n = str.length();
    bool res = true;

    stack<char> st;

    for(int i=0;i<n;i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            st.push(str[i]);
        }
        else if(str[i]==')'){
            if(st.top()!='('){
                res = false;
                break;
            }
            else{
                st.pop();
            }
        }
        else if(str[i]=='}'){
            if(st.top()!='{'){
                res = false;
                break;
            }
            else{
                st.pop();
            }
        }
        else if(str[i]==']'){
            if(st.top()!='['){
                res = false;
                break;
            }
            else{
                st.pop();
            }
        }
    }
    if(!st.empty()){
        res = false;
    }
    return res;
}

int main(){
    string str;
    cout<<"\nenter a equation with nested brackets: ";
    getline(cin,str);

    if(isValid(str)){
        cout<<"entered equation "<<str<<" is a valid equation!"<<endl;
    }
    else{
        cout<<"entered equation "<<str<<" is not a valid equation!"<<endl;
    }

    return 0;
}