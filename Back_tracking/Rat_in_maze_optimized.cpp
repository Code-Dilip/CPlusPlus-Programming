#include<iostream>
#include<vector>
#include<string>
using namespace std;

void helper(vector<vector<int>> &maze,vector<string> &ans, string path,int r,int c){
    int n = maze.size();
    if(r<0||c<0||r>=n||c>=n||maze[r][c]==0||maze[r][c]==-1){
        return ;
    }
    if(r==n-1 && c==n-1){
        ans.push_back(path);
        return ;
    }
    maze[r][c] = -1;
    helper(maze,ans,path+"D",r+1,c); //Down
    helper(maze,ans,path+"U",r-1,c); //Up
    helper(maze,ans,path+"L",r,c-1); //Left
    helper(maze,ans,path+"R",r,c+1); //Right
    maze[r][c] = 1;
}

int main(){
    vector<vector<int>> maze = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    vector<string> ans;
    string path = " ";
    helper(maze,ans,path,0,0);
    for(string str: ans){
        cout<<str<<endl;
    }
    cout<<endl;
    return 0;
}