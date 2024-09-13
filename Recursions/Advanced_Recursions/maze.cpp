#include<iostream>

using namespace std;

int countPathMaze(int n,int i,int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>n-1 || j>n-1){
        return 0;
    }
    return countPathMaze(n,i+1,j)+countPathMaze(n,i,j+1);
}

int main(){
    int n;
    cout<<"\nenter the size of the maze: ";
    cin>>n;
    cout<<"There are "<<countPathMaze(n,0,0)<<" ways to reach the end of the maze!"<<endl;
    cout<<endl;
    return 0;
}