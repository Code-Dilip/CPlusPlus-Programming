#include<iostream>
#include<string>

using namespace std;

class student{
    string name;
    string srn;
    string branch;
    
    public:
    student(){
        cout<<"\nenter the student name: ";
        getline(cin,name);
        cout<<"enter the srn: ";
        getline(cin,srn);
        cout<<"enter the branch: ";
        getline(cin,branch);
    }

    public:
    void display(){
        cout<<"\nStudent Name: "<<name<<endl;
        cout<<"SRN: "<<srn<<endl;
        cout<<"Branch: "<<branch<<endl;
    }
};

int main(){
    student s1;
    s1.display();

    cout<<endl;
    return 0;
}