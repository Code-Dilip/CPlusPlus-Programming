#include<iostream>
#include<vector>
#include<string>
using namespace std;


bool isSafe(vector<string>&board, int row, int col,int n){

    for(int j=0;j<n;j++){ // Horizontal
        if(board[row][j]=='Q'){
            return false;
        }
    }

    for(int i=0;i<n;i++){ //veritcal
        if(board[i][col]=='Q'){
            return false;
        }
    }
    
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){  //left Diagonal
        if(board[i][j]=='Q'){
            return false;
        }
    }

    for(int i=row,j=col;i>=0 && j<n;i--,j++){ //right Diagonal
        if(board[i][j]=='Q'){
            return false;
        }    
    }

    return true;

}


void nQueens(vector <string> &board, vector <vector<string>> &ans,int row,int n){
    if(row == n){
        ans.push_back(board);
        return ;
    }

    for(int j=0;j<n;j++){
        if(isSafe(board,row,j,n)){
            board[row][j] = 'Q';
            nQueens(board,ans,row+1,n);
            board[row][j] = '.';
        }
    }
}

int main(){
    int n = 4;
    vector <string> board(n,string(n,'.'));
    vector <vector <string>> ans;
    nQueens(board,ans,0,n);

    for(vector <string> board: ans){
        for(string str: board){
            for(char c: str){
                cout<<c<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}