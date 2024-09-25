#include<iostream>
#include<string>

using namespace std;

class shape{
    public:
    float length,width;
    public:
    shape(){
        cout<<"\nenter the length: ";
        cin>>length;
        cout<<"enter the width: ";
        cin>>width;
    }
    void display(){
        cout<<"\nLenght = "<<length<<endl;
        cout<<"Width = "<<width<<endl;
    }
};

class parameters : public shape{
    float area,perimeter;
    public:
    parameters(){
        area = length * width;
        perimeter = 2*(length+width);
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