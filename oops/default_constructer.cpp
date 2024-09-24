#include<iostream>
#include<string>

using namespace std;

class bank{
    public:
    string name;
    float amount;
    bank(){
        cout<<"\nenter the name of the account holder: ";
        getline(cin,name);
        cout<<"enter the amount: ";
        cin>>amount;
    }

    void display(){
        cout<<"\nAccount Holder: "<<name<<endl;
        cout<<"Amount: "<<amount<<endl;
    }
};

int main(){
    
    bank p1;
    p1.display();
    
    bank p2;
    p2.display();

    cout<<endl;
    return 0;
}