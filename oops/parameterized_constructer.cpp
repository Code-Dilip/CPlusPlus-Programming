#include<iostream>
#include<string>

using namespace std;

class bank{
    public:
    string name;
    float amount;
    
    bank(string n,float a){
        name = n;
        amount = a;
    }

    void display(){
        cout<<"\nAccount Holder Name: "<<name<<endl;
        cout<<"Amout: "<<amount<<endl;
    }
};

int main(){
    
    bank b1("Dilip",250);
    b1.display();
     
    cout<<endl;
    return 0;
}