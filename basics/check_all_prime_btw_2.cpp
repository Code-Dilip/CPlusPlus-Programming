#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n,m,i,j,flag = 0;
    cin>>n>>m;
    cout<<""<<endl;
    for(i=n;i<=m;i++){
        for(j=2;j<sqrt(i);j++){
            if((i%j)==0){
                flag = 1;
                break;
            }
        }
        if(!flag){
            cout<<i<<endl;
        }
    }

    return 0;
}