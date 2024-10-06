#include<iostream>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;

int precedence(char a){
    if(a=='^'){
        return 3;
    }
    else if(a=='*' || a=='/'){
        return 2;
    }
    else if(a=='+' || a=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

string infixToPrefix(string s){
    string res;
    stack<char> st;

    reverse(s.begin(),s.end());

    for(int i=0;i<s.length();i++){
        if(s[i]==' ' || s[i]=='\t'){
            continue;
        }
        else if(s[i]>='a' && s[i]<='z'){
            res += s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
                res += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && precedence(s[i])<=precedence(st.top())){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    string infix,prefix;
    cout<<"\nenter a infix expression: ";
    getline(cin,infix);
    
    prefix = infixToPrefix(infix);
    cout<<"\nThe infix expression "<<infix<<" after converting to prefix is "<<prefix<<endl;
    return 0;
}