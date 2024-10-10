#include<iostream>
#include<string>

using namespace std;

class node {
    public:
    char data;
    node *prev;
    node *next;
    public:
    node (char val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class stack  {
    node *top;
    node *bottom ;
    public: 
    stack(){
        top = nullptr;
        bottom = nullptr;
    }

    void push(char x){
        node *newp = new node(x);
        if(newp == nullptr){
            cout<<"Stack Overflow!"<<endl;
            return ;
        }
        if(top == nullptr){
            top = newp;
            bottom = newp;
            return ;
        }
        top->next = newp;
        newp->prev = top;
        top = newp;
    }

    void pop(){
        if(top == nullptr){
            cout<<"Stack is Empty!"<<endl;
            return;
        }
        node *toDelete = top;
        top = top->prev;
        if(top == nullptr){
            bottom = nullptr;
        }
        else{
            top->next = nullptr;
        }
        free(toDelete);
    }

    char seek(){
        if(top == nullptr){
            cout<<"Stack is Empty!"<<endl;
            return ' ';
        }
        return top->data;
    }

    bool empty(){
        if(top == nullptr){
            return 1;
        }
        return 0;
    }

    void print(){
        if(bottom == nullptr){
            return ;
        }
        node *temp = bottom;
        cout<<"[ ";
        while(temp->next != nullptr){
            cout<<temp->data<<",";
            temp = temp->next;
        }
        cout<<temp->data<<"] "<<endl;
    }
};

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
    string res =  "";
    stack st;

    for(int i=0;i<s.length();i++){
        if(s[i]==' ' || s[i]=='\t'){
            continue;
        }
        else if(s[i]>='0' && s[i]<='9'){
            res += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.seek()!='('){
                res += st.seek();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && precedence(s[i])<=precedence(st.seek())){
                res += st.seek();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res += st.seek();
        st.pop();
    }
    return res;
}

int main(){
    string infix,postfix;
    cout<<"\nenter a infix expression: ";
    getline(cin,infix);
    
    postfix = infixToPostfix(infix);
    cout<<"\nThe infix expression "<<infix<<" after converting to postfix is "<<postfix<<endl;
    return 0;
}