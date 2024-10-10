#include<iostream>
#include<string>

using namespace std;

class node {
    public:
    string data;
    node *prev;
    node *next;
    public:
    node (string val){
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

    void push(string x){
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

    string seek(){
        if(top == nullptr){
            cout<<"Stack is Empty!"<<endl;
            return "";
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

void reverseSentence(string str){
    stack st;
    for(int i=0;i<str.length();i++){
        string word = "";
        while(str[i] != ' '){
            word += str[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.seek()<<endl;
        st.pop();
    }
    cout<<endl;
    return ;
}

int main(){
   cout<<endl;
   string str;
   string res;
   cout<<"enter a string: ";
   getline(cin,str);

   cout<<"The string "<<str<<" after reversing is ";
   reverseSentence(str);
   cout<<endl;
   cout<<endl;
   return 0;
}