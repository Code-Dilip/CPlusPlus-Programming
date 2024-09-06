#include<iostream>
using namespace std;

void input_matrix(int *mat,int n,int m){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"enter the elements in the #"<<i+1<<" row of the matrix"<<endl;
        for(int j=0;j<m;j++){
            cin>>*((mat+i*m)+j);
        }
    }
    cout<<endl;
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
    cout<<endl;
}

void transpose(int *mat,int *res,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            *((res+j*n)+i) = *((mat+i*m)+j);
        }
    }
}


int main(){
    int n,m;
    cout<<"\nenter the no. of rows in the matrix: ";
    cin>>n;
    cout<<"enter the no. of columns in the matrix: ";
    cin>>m;

    int mat[n][m],res[m][n];
    cout<<"\nenter the elements in the matrix ";
    input_matrix(*mat,n,m);
    cout<<"The matrix before transpose operation is ";
    print_matrix(*mat,n,m);
    transpose(*mat,*res,n,m);
    cout<<"The transposed matrix is ";
    print_matrix(*res,m,n);

    cout<<endl;
    return 0;
}