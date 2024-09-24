#include<iostream>
#include<string>

using namespace std;

class student {
    public:
    string name;
    string srn;
    string branch;

    void display(){
        cout<<"\nStudent Name: "<<name<<endl;
        cout<<"SRN: "<<srn<<endl;
        cout<<"Branch: "<<branch<<endl;
    }
};

int main(){
    
    student s1;
    cout<<"\nenter the name of the student: ";
    getline(cin,s1.name);
    cout<<"enter the srn of the student: ";
    getline(cin,s1.srn);
    cout<<"enter the branch of the student: ";
    getline(cin,s1.branch);
    s1.display();
    
    cout<<endl;
    return 0;
}