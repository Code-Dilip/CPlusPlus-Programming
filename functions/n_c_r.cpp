#include<iostream>
using namespace std;

int fact(int n){
    if(n<0){
        return -1;
    }
    else if(n==0 || n==1){
        return 1;
    }
    else{
        int fact = 1;
        for(int i=1;i<=n;i++){
            fact *= i;
        }
        return fact;
    }
}

int ncr(int n,int r){
    return(fact(n)/((fact(n-r)*fact(r))));
}

int main(){
    int n,r;
    cin>>n>>r;
    cout<<endl<<ncr(n,r)<<endl;
    return 0;
}