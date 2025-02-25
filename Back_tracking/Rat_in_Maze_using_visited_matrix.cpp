#include<iostream>
#include<vector>
#include<string>
using namespace std;


void helper(vector<vector<int>> &maze,vector<string> &ans,vector<vector<bool>> vis, string path,int r,int c){
    int n = maze.size();
    if(r<0||c<0||r>=n||c>=n||maze[r][c]==0||vis[r][c]==true){
        return ;
    }
    if(r==n-1 && c==n-1){
        ans.push_back(path);
        return ;
    }
    vis[r][c] = true;
    helper(maze,ans,vis,path+"D",r+1,c); //Down
    helper(maze,ans,vis,path+"U",r-1,c); //Up
    helper(maze,ans,vis,path+"L",r,c-1); //Left
    helper(maze,ans,vis,path+"R",r,c+1); //Right
    vis[r][c] = false;
}

int main(){
    vector<vector<int>> maze = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };
    string path = "";
    vector <vector<bool>> vis(maze.size(),vector<bool>(maze.size(),false));
    vector<string> ans;

    helper(maze,ans,vis,path,0,0);
    for(string str: ans){
        cout<<str<<endl;
    }
    return 0;
}