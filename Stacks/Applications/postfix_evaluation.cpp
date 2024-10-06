#include<iostream>
#include<string>
#include<stack>
#include<math.h>

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

string infixToPostfix(string s){
    string res;
    stack<char> st;

    for(int i=0;i<s.length();i++){
        if(s[i]==' ' || s[i]=='\t'){
            continue;
        }
        else if(s[i]>='0' && s[i]<='9'){
            res += s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
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
    return res;
}

int postfixEvaluation(string s){
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op2  = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch(s[i]){
                case '+': st.push(op1+op2);
                break;
                case '-': st.push(op1-op2);
                break;
                case '*': st.push(op1*op2);
                break;
                case '/': st.push(op1/op2);
                break;
                case '^': st.push(pow(op1,op2));
                break;
            }
        }
    }
    return st.top();
}

int main(){
    string infix,postfix;
    cout<<"\nenter a infix expression: ";
    getline(cin,infix);
    
    postfix = infixToPostfix(infix);
    cout<<"\nThe infix expression "<<infix<<" after converting to postfix is "<<postfix<<endl;
    cout<<""<<postfix<<" = "<<postfixEvaluation(postfix)<<endl;
    cout<<endl;
    return 0;
}