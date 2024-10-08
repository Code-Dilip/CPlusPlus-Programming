#include<iostream>
using namespace std;

void input_matrix(int *mat,int n){
    cout<<"enter the elements in the matrix "<<endl;
    for(int i=0;i<n;i++){
        cout<<"enter the elements of #"<<i+1<<" row: "<<endl;
        for(int j=0;j<n;j++){
            cin>>*((mat+i*n)+j);
        }
    }
    cout<<endl;
}

void print_matrix(int *mat,int n){
    for(int i=0;i<n;i++){
        cout<<"[";
        for(int j=0;j<n;j++){
            cout<<" "<<*((mat+i*n)+j);
        }
        cout<<" ]"<<endl;
    }
    cout<<endl;
}

void transpose_matrix(int *mat,int *res,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *((res+i*n)+j) = *((mat+j*n)+i);
        }
    }
}

int main(){
    int n;
    cout<<"\nSquare matrix!"<<endl;
    cout<<"enter the number of rows in the matrix: ";
    cin>>n;

    int mat[n][n],res[n][n];
    input_matrix(*mat,n);
    cout<<"\nThe matrix before transpose is "<<endl;
    print_matrix(*mat,n);

    transpose_matrix(*mat,*res,n);
    cout<<"\nThe transposed matrix is "<<endl;
    
    print_matrix(*res,n);

    cout<<endl;
    return 0;
}