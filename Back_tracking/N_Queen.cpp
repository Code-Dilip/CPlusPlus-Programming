#include<iostream>

using namespace std;

bool isSafe(int **arr,int x,int y,int n){
    if((x<n && y<n) && arr[x][y] == 1){
        return true;
    }
    return false;
}

bool ratInMaze(int **arr,int **sol_arr,int x,int y,int n){
    if(x==n-1 && y==n-1){
        sol_arr[x][y] = 1;
        return true;
    }
    if(isSafe(arr,x,y,n)){
        sol_arr[x][y] = 1;
        if(ratInMaze(arr,sol_arr,x+1,y,n)){
            return true;
        }
        if(ratInMaze(arr,sol_arr,x,y+1,n)){
            return true;
        }
        sol_arr[x][y] = 0;
        return false;
    }
    return false;
}

int main(){
    int n;
    cout<<"\nenter the size of the maze: ";
    cin>>n;
    int **arr = new int*[n];
    int **sol_arr = new int *[n];
    
    cout<<"enter the maze!\n";
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i+1<<" of the matrix! "<<endl;
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }

    for(int i=0;i<n;i++){
        sol_arr[i] = new int[n];
        for(int j=0;j<n;j++){
            sol_arr[i][j] =  0;
        }
    }

    cout<<"\nThe maze entered is: ";
    for(int i=0;i<n;i++){
        cout<<endl;
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;


    if(ratInMaze(arr,sol_arr,0,0,n)){
        cout<<"\nThe solution for the given maze is: ";
        for(int i=0;i<n;i++){
            cout<<endl;
            for(int j=0;j<n;j++){
               cout<<sol_arr[i][j]<<" ";
               }
            }
        cout<<endl;
    }

    cout<<endl;
    return 0;
}