#include<iostream>
using namespace std;

int fact(int num){
    if(num<0){
        return -1;
    }
    else if(num==0 || num==1){
        return 1;
    }
    else{
        int fact=1;
        for(int i=1;i<=num;i++){
            fact *= i;
        }
        return fact;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<fact(n);
    cout<<endl;
    return 0;
}