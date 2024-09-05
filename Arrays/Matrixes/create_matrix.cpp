#include<iostream>
using namespace std;

void input_matrix(int *mat,int n,int m){
    for(int i=0;i<n;i++){
        cout<<"enter the elements of #"<<i+1<<" row: "<<endl;
        for(int j=0;j<m;j++){
            cin>>*((mat+i*m)+j);
        }
        cout<<endl;
    }
}

void print_matrix(int *mat,int n,int m){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"[";
        for(int j=0;j<m;j++){
            cout<<" "<<*((mat+i*m)+j);
        }
        cout<<" ]"<<endl;
    }
}

int main(){
    
    int n,m;
    cout<<"\nenter the no. of rows in the matrix: ";
    cin>>n;
    cout<<"enter the no. of column in the matrix: ";
    cin>>m;
    int mat[n][m];

    cout<<"\nenter the first matrix: "<<endl;
    input_matrix((int *)mat,n,m);
    
    cout<<"The matrix is ";
    print_matrix((int *)mat,n,m);

    cout<<endl;
    return 0;
}