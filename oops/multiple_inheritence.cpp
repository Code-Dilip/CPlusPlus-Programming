#include<iostream>
#include<string>

using namespace std;

class person{
    string name;
    string gender;
    int age;
    public:
    void getData(){
        cout<<"\nenter the name: ";
        getline(cin,name);
        cout<<"enter the gender: ";
        getline(cin,gender);
        cout<<"enter the age: ";
        cin>>age;
    }
    void display(){
        cout<<"\nName: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Gender: "<<gender<<endl;
    }
};

class student{
    public:
    string branch;
    int srn;
    void getData2(){
        cout<<"enter the SRN: ";
        cin>>srn;
        cout<<"enter the branch: ";
        cin>>branch;
    }
    void display1(){
        cout<<"Branch: "<<branch<<endl;
        cout<<"SRN: "<<srn<<endl;
    }
};

class research_student:public person,public student{
    string research_topic;
    int no_paper_published;
    int experience;
    public:
    research_student(){
        cout<<"\nEnter the Reasearch Student Details ! "<<endl;
        getData();
        getData2();
        cout<<"enter the no. of paper's published: ";
        cin>>no_paper_published;
        cout<<"enter the no. of year of experience: ";
        cin>>experience;
        cout<<"enter the research subject of the student: ";
        getline(cin,research_topic);
    }
    void display2(){
        cout<<"\nThe Details of research student!"<<endl;
        display();
        display1();
        cout<<"Research Topic: "<<research_topic<<endl;
        cout<<"No. of Paper Published: "<<no_paper_published<<endl;
        cout<<"No. of years of Experience: "<<experience<<endl;
    }
};

int main(){
    
    research_student rs1;
    rs1.display2();

    cout<<endl;
    return 0;
}