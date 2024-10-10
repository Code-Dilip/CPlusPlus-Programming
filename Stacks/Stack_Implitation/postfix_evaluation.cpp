#include<iostream>
#include<string>
#include<stack>
#include<math.h>

using namespace std;

class int_node {
    public:
    char data;
    int_node *prev;
    int_node *next;
    public:
    int_node (char val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class char_node {
    public:
    char data;
    char_node *prev;
    char_node *next;
    public:
    char_node (char val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class stack_int  {
    int_node *top;
    int_node *bottom ;
    public: 
    stack_int(){
        top = nullptr;
        bottom = nullptr;
    }

    void push(int x){
        int_node *newp = new int_node(x);
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
            return;
        }
        int_node *toDelete = top;
        top = top->prev;
        if(top == nullptr){
            bottom = nullptr;
        }
        else{
            top->next = nullptr;
        }
        free(toDelete);
    }

    int seek(){
        if(top == nullptr){
            return -1;
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
        int_node *temp = bottom;
        cout<<"[ ";
        while(temp->next != nullptr){
            cout<<temp->data<<",";
            temp = temp->next;
        }
        cout<<temp->data<<"] "<<endl;
    }
};

class stack_char  {
    char_node *top;
    char_node *bottom ;
    public: 
    stack_char(){
        top = nullptr;
        bottom = nullptr;
    }

    void push(char x){
        char_node *newp = new char_node(x);
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
            return;
        }
        char_node *toDelete = top;
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
        char_node *temp = bottom;
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
    string res;
    stack_char st;

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

int postfixEvaluation(string s){
    stack_int st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op2  = st.seek();
            st.pop();
            int op1 = st.seek();
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
    return st.seek();
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