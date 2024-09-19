#include<iostream>

using namespace std;

bool isSafe(int **arr,int x,int y,int n){
    for(int row = 0;row<x;row++){
        if(arr[row][y] == 1){
            return false;
        }
    }
    int row = x;
    int col = y;
    while(row>=0 && col>=0){
        if(arr[row][col] == 1){
            return false;
        }
        row --;
        col --;
    }
    row = x;
    col = y;
    while(row>=0 && col<n){
        if(arr[row][col] == 1){
            return false;
        }
        row --;
        col ++;
    }
    return true;
}

bool NQueen(int **arr,int x,int n){
    if(x>=n){
        return true;
    }
    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col] = 1;
            if(NQueen(arr,x+1,n)){
                return true;
            }
            arr[x][col] = 0;
        }
    }
    return false;
}

int main(){
    int n;
    cout<<"\nenter the size of the maze: ";
    cin>>n;
    int **solarr = new int*[n];

    for(int i=0;i<n;i++){
        solarr[i] = new int[n];
        for(int j=0;j<n;j++){
            solarr[i][j] = 0;
        }
    }

    cout<<"\nThe solution for N-Queen problem !";
    if(NQueen(solarr,0,n)){
        for(int i=0;i<n;i++){
            cout<<endl;
            for(int j=0;j<n;j++){
                cout<<solarr[i][j]<<" ";
            }
        }
    }

    cout<<endl;
    return 0;
}