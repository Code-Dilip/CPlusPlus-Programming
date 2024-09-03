#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n,i,flag=0;
    cin>>n;
    
    for(i=2;i<sqrt(n);i++){
        if((n%i)==0){
            flag = 1;
            break;
        }
    }

    if(flag){
        cout<<"Non Prime number!"<<endl;
    }
    else{
        cout<<"Prime number!"<<endl;
    }

    return 0;
}