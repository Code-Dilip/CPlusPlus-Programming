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
    return ((fact(n))/((fact(n-r))*fact(r)));
}

void pascals_triangle(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<ncr(i,j)<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    cout<<endl;
    pascals_triangle(n);
    cout<<endl;
    return 0;
}