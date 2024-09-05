#include<iostream>
using namespace std;

void input_matrix(int *mat,int n,int m){
    cout<<"enter the elements in the matrix "<<endl;
    for(int i=0;i<n;i++){
        cout<<"enter the elements of #"<<i+1<<" row: "<<endl;
        for(int j=0;j<m;j++){
            cin>>*((mat+i*m)+j);
        }
        cout<<endl;
    }
}

void print_matrix(int *mat,int n,int m){
    cout<<"The matrix is "<<endl;
    for(int i=0;i<n;i++){
        cout<<"[";
        for(int j=0;j<m;j++){
            cout<<" "<<*((mat+i*m)+j);
        }
        cout<<" ]"<<endl;
    }
}

void insertion_sort(int *mat,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            int k = j-1;
            int curr_ele = *((mat+i*m)+j);
            while(*((mat+i*m)+k)>curr_ele && k>=0){
                *((mat+i*m)+(k+1)) = *((mat+i*m)+k);
                k --;
            }
            *((mat+i*m)+(k++)) = curr_ele;
        }
    }

    /*for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            int k = j-1;
            int curr_ele = *((mat+j*m)+i);
            while(*((mat+k*m)+i)>curr_ele){
                k --;
            }
            *((mat+(k++)*m)+i) = curr_ele;
        }
    }*/
}

int main(){
    int n,m;
    cout<<"\n enter the no. of rows in the matrix: ";
    cin>>n;
    cout<<"enter the no. of columns in the matrix: ";
    cin>>m;
    cout<<endl;

    int mat[n][m];
    input_matrix((int *)mat,n,m);
    cout<<"Before Sorting ";
    print_matrix((int *)mat,n,m);
    
    insertion_sort((int *)mat,n,m);
    cout<<"After sorting ";
    print_matrix((int *)mat,n,m);

    cout<<endl;
    return 0;
}