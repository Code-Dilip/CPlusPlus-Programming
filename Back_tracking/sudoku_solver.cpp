#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(vector<vector<char>> &board,int row,int col,int dig){
        
    for(int j=0;j<9;j++){ // Horizontal
        if(board[row][j]==dig){
            return false;
        }
    }

    for(int i=0;i<9;i++){ // Vertical
        if(board[i][col]==dig){
            return false;
        }
    }

    int s_row = (row/3)*3;
    int s_col = (col/3)*3;
    for(int i=s_row;i<=s_row+2;i++){
        for(int j=s_col;j<=s_col+2;j++){
            if(board[i][j]==dig){
                return false;
            }
        }
    }

    return true;

}

bool helper(vector<vector<char>> &board, int row,int col){
    if(row == 9){
        return true;
    }
    int next_row = row, next_col = col+1;
    if(next_col==9){
        next_row = row+1;
        next_col = 0;
    }

    if(board[row][col]!='.'){
        return helper(board,next_row,next_col);
    }
    for(char dig='1';dig<='9';dig++){
        if(isSafe(board,row,col,dig)){
            board[row][col] = dig;
            if(helper(board,next_row,next_col)){
                return true;
            }
            board[row][col] = '.';
        }
    }
    return false;
}

int main(){
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    } ;

    helper(board,0,0);

    for(vector<char> row: board){
        for(char cell: row){
            cout<<cell<<" ";
        }
        cout<<endl;
    }
    return 0;
}