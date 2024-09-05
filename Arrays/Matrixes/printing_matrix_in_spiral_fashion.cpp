#include<iostream>
using namespace std;

void input_matrix(int *mat,int n,int m){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"enter the elements of the #"<<i+1<<" row: "<<endl;
        for(int j=0;j<m;j++){
            cin>>*((mat+i*m)+j);
        }
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

void print_matrix_spiraly(int *mat,int n,int m){

    int row_start=0,row_end=n-1,column_start=0,column_end=m-1;
    cout<<endl;
    while(row_start<=row_end && column_start<=column_end){
        cout<<"[";
        for(int col=column_start;col<=column_end;col++){
            cout<<" "<<*((mat+row_start*m)+col);
        }
        cout<<" ]"<<endl;
        row_start ++;

        cout<<"[";
        for(int row=row_start;row<=row_end;row++){
            cout<<" "<<*((mat+row*m)+column_end);
        }
        cout<<" ]"<<endl;
        column_end --;

        cout<<"[";
        for(int col=column_end;col>=column_start;col--){
            cout<<" "<<*((mat+row_end*m)+col);
        }
        cout<<" ]"<<endl;
        row_end --;

        cout<<"[";
        for(int row=row_end;row>=row_start;row--){
            cout<<" "<<*((mat+row*m)+column_start);
        }
        cout<<" ]"<<endl;
        column_start ++;
    }
}

int main(){
    int n,m;
    cout<<"\nenter the no. of rows in the matrix: ";
    cin>>n;
    cout<<"enter the no. of columns in the matrix: ";
    cin>>m;
    int mat[n][m];

    cout<<"\nenter the elements of the matrix ";
    input_matrix((int *)mat,n,m);

    cout<<"\nThe matrix is ";
    print_matrix((int *)mat,n,m);

    cout<<"\nThe matrix in spiral order is ";
    print_matrix_spiraly((int *)mat,n,m);

    cout<<endl;
    return 0;
}