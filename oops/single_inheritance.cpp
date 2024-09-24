#include<iostream>
#include<string>

using namespace std;

class shape{
    public:
    float width;
    float length;
    public:
    shape(){
        cout<<"\nenter the width: ";
        cin>>width;
        cout<<"enter the length: ";
        cin>>length;
    }
    void display(){
        cout<<"\nLength = "<<length<<endl;
        cout<<"Width = "<<width<<endl;
    }
};

class parameters : public shape{
    float area;
    float perimeter;
    public:
    parameters(){
        area = width * length;
        perimeter = 2*(length + width);
    }
    void display1(){
        display();
        cout<<"Area = "<<area<<endl;
        cout<<"Perimeter = "<<perimeter<<endl;
    }
};

int main(){

    parameters rec;
    rec.display1();

    cout<<endl;
    return 0;
}