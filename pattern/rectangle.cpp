#include<iostream>
using namespace std;

int main(){
    int row,col,i,j;
    cin>>row>>col;
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    return 0;
}