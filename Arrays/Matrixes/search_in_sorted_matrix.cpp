#include<iostream>
#include<climits>
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
    cout<<"\nThe matrix is "<<endl;
    for(int i=0;i<n;i++){
        cout<<"[";
        for(int j=0;j<m;j++){
            cout<<" "<<*((mat+i*m)+j);
        }
        cout<<" ]"<<endl;
    }
}

void is_there(int *mat,int n,int m,int key){
    int row=0,column=m-1,flag=0;
    while(row<n && column>=0){
        if(*((mat+row*m)+column)==key){
            flag = 1;
            break;
        }
        else if(*((mat+row*m)+column)>key){
            column --;
        }
        else{
            row ++;
        }
    }
    if(flag){
        cout<<"The search key "<<key<<" is at ("<<row<<","<<column<<") position."<<endl;
    }
    else{
        cout<<"The search key "<<key<<" is not present in the matrix."<<endl;
    }
}

int main(){
    int n,m;
    cout<<"\n enter the no. of rows in the matrix: ";
    cin>>n;
    cout<<"enter the no. of columns in the matrix: ";
    cin>>m;
    cout<<endl;

    int mat[n][m],key;
    input_matrix((int *)mat,n,m);
    print_matrix((int *)mat,n,m);
    
    char repeat='y';
    cout<<"\n"<<endl;
    while(repeat == 'y' || repeat=='Y'){
        cout<<"enter the search key: ";
        cin>>key;
        is_there((int *)mat,n,m,key);
        cout<<"want to search more elemtns? (y/n):";
        cin>>repeat;
    }
    
    cout<<endl;
    return 0;
}