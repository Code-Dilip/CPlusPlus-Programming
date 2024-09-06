#include<iostream>
using namespace std;

void input_matrix(int *mat,int n,int m){
    cout<<"\nenter the elements int the matrix"<<endl;
    for(int i=0;i<n;i++){
        cout<<"enter the elements in the #"<<i+1<<" row of the matrix"<<endl;
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
    cout<<endl;
}

void insertion_sort(int *arr,int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int curr_element = *(arr+i);
        while(j>=0 && curr_element<*(arr+j)){
            *(arr+(j+1)) = *(arr+j);
            j --;
        }
        *(arr+(j+1)) = curr_element;
    }
}

void insertion_sort_matrix(int *mat,int n,int m){
    //sorting rows in ascending order
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            int k=j-1;
            int curr_element = *((mat+i*m)+j);
            while(k>=0 && curr_element < *((mat+i*m)+k)){
                *((mat+i*m)+(k+1)) = *((mat+i*m)+k);
                k --;
            }
            *((mat+i*m)+(k+1)) = curr_element;
        }
    }
    //sorting columns in ascending order
    for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            int k=i-1;
            int curr_element = *((mat+i*m)+j);
            while(k>=0 && curr_element < *((mat+k*m)+j)){
                *((mat+(k+1)*m)+j) = *((mat+k*m)+j);
                k --;
            }
            *((mat+(k+1)*m)+j) = curr_element;
        }
    }
}

void search_ele(int *mat,int n,int m,int key){
    int row = 0,column = m-1;
    bool flag;
    while(row<n && column>=0){
        if(*((mat+row*m)+column) == key){
            flag = 1;
            break;
        }
        else if(*((mat+row*m)+column) > key){
            column --;
        }
        else{
            row ++;
        }
    }
    if(flag){
        cout<<"The search element "<<key<<" is present in the matrix. "<<endl;
    }
    else{
        cout<<"The search element "<<key<<" is not present in the matrix. "<<endl;
    }
}

int main(){
    int n,m;
    cout<<"\nenter the no. of rows in the matrix: ";
    cin>>n;
    cout<<"enter the no. of columns in the matrix: ";
    cin>>m;
    
    int mat[n][m],key;
    char ws='y';
    input_matrix(*mat,n,m);
    cout<<"\nThe matrix before sorting is ";
    print_matrix(*mat,n,m);

    insertion_sort_matrix(*mat,n,m);
    cout<<"\nThe matrix after sorting is ";
    print_matrix(*mat,n,m);

    while(ws=='y' || ws=='Y'){
        cout<<"\nenter the key to search in the matrix: ";
        cin>>key;
        search_ele(*mat,n,m,key);
        cout<<"want to search more elements ?"<<endl;
        cout<<"press (y/n): ";
        cin>>ws;
    }

    cout<<endl;
    return 0;
}