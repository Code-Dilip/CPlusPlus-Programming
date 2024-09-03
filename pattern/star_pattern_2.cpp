#include<iostream>
using namespace std;

int main(){
    int n,j;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(j=1;j<=(n-i);j++){
            cout<<"  ";
        }
        for(j=i;j>1;j--){
            cout<<"* ";
        }
        for(;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=n-1;i>=1;i--){
        for(j=1;j<=(n-i);j++){
            cout<<"  ";
        }
        for(j=i;j>1;j--){
            cout<<"* ";
        }
        for(;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    return 0;
}