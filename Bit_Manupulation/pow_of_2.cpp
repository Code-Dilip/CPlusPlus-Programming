#include<iostream>

using namespace std;

bool ispowerof2(int n){
    return n && !(n&(n-1));
}

int main(){

    cout<<endl;
    cout<<ispowerof2(1)<<endl;
    cout<<ispowerof2(2)<<endl;
    cout<<ispowerof2(3)<<endl;
    cout<<ispowerof2(4)<<endl;
    cout<<ispowerof2(5)<<endl;
    cout<<ispowerof2(6)<<endl;
    cout<<ispowerof2(7)<<endl;
    cout<<ispowerof2(8)<<endl;
    cout<<ispowerof2(9)<<endl;
    cout<<ispowerof2(10)<<endl;
    cout<<endl;
    
    return 0;
}