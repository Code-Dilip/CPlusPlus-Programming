#include<iostream>
using namespace std;

void input_matrix(int *mat,int n,int m,int k){
    cout<<"\nenter the elements of #"<<k<<" matrix "<<endl;
    for(int i=0;i<n;i++){
        cout<<"enter the elements of #"<<i+1<<" row of #"<<k<<" matrix "<<endl;
        for(int j=0;j<m;j++){
            cin>>*((mat+i*m)+j);
        }
    }
    cout<<endl;
}

void print_matrix(int *mat,int n,int m,int k){
    cout<<"The #"<<k<<" matrix is "<<endl;
    for(int i=0;i<n;i++){
        cout<<"[";
        for(int j=0;j<m;j++){
            cout<<" "<<*((mat+i*m)+j);
        }
        cout<<" ]"<<endl;
    }
}

void mat_mul(int *mat1,int n1,int m1,int *mat2,int n2,int m2){
    if(m1!=n2){
        cout<<"\n matrix multiplication is not possible as no. of columns in first matrix and no. of rows in second matrix does'nt match"<<endl;
        return ;
    }
    int res[n1][m2];
    for(int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            res[i][j] = 0;
            for(int k=0;k<m1;k++){
                res[i][j] +=  *((mat1+i*m1)+k) * *((mat2+k*m2)+j);
            }
        }
    }
    cout<<"\nThe resutant matrix is "<<endl;
    for(int i=0;i<n1;i++){
        cout<<"[";
        for(int j=0;j<m2;j++){
            cout<<" "<<res[i][j];
        }
        cout<<" ]"<<endl;
    }
}

int main(){
    int n1,m1,n2,m2;
    cout<<"\nenter the no. of rows of first matrix: ";
    cin>>n1;
    cout<<"enter the no. of columns of first matrix: ";
    cin>>m1;
    int mat1[n1][m1];
    input_matrix((int *)mat1,n1,m1,1);
    print_matrix((int *)mat1,n1,m1,1);

    cout<<"\nenter the no. of rows of second matrix: ";
    cin>>n2;
    cout<<"enter the no. of columns of second matrix: ";
    cin>>m2;
    int mat2[n2][m2];
    input_matrix((int *)mat2,n2,m2,2);
    print_matrix((int *)mat2,n2,m2,2);
    cout<<endl;

    mat_mul((int *)mat1,n1,m1,(int *)mat2,n2,m2);

    cout<<endl;
    return 0;
}