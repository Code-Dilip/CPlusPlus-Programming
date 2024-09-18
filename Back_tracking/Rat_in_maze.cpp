#include<iostream>

using namespace std;

bool isSafe(int **arr,int x,int y,int n){
    if(arr[x][y]==1 && (x<n && y<n)){
        return true;
    }
    return false;
}

bool ratInMaze(int **arr,int **solarr,int x,int y,int n){
    if(x==n-1 && y==n-1){
        solarr[x][y] = 1;
        return true;
    }
    
    if(isSafe(arr,x,y,n)){
        solarr[x][y] = 1;
        if(ratInMaze(arr,solarr,x+1,y,n)){
            return true;
        }
        if(ratInMaze(arr,solarr,x,y+1,n)){
            return true;
        }
        solarr[x][y] = 0;
        return false;
    }
    return false;
}

int main(){
    int n;
    cout<<"\nenter the size of the maze: ";
    cin>>n;
    int **arr = new int*[n];
    int **solarr = new int*[n];
    
    cout<<"enter the maze elements: "<<endl;
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    cout<<"\nThe maze entered is \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<n;i++){
        solarr[i] = new int[n];
        for(int j=0;j<n;j++){
            solarr[i][j] = 0;
        }
    }
    
    cout<<"\nThe solution for the maze is: \n";
    if(ratInMaze(arr,solarr,0,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<solarr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}