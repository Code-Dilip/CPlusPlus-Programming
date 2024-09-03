#include<iostream>
using namespace std;

int reverse(int num){
    int rev=0;
    while(num != 0){
        rev *= 10;
        rev += (num%10);
        num /= 10;
    }
    return rev;
}

int main(){
    int n;
    cin>>n;
    if(n == reverse(n)){
        cout<<"Armstrong number!";
    }
    else{
        cout<<"Non Armstrong number!"<<endl;
    }
    cout<<endl;
    return 0;
}