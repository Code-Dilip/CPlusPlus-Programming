#include<iostream>
#include<vector>
using namespace std;

void set_matrix_zeros(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    //vector <int> row(n,0);->matrix[..,][0]; first column
    //vector<int> col(m,0);->matrix[0][...]; first row
    int col0 = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                //mark ith row
                matrix[i][0] = 0;
                //mark jth col
                if(j!=0){
                    matrix[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
                //check row and col
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }

    if(matrix[0][0]==0){
        for(int j=0;j<m;j++){
            matrix[0][j] = 0;
        }
    }
    
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0] = 0;
        }
    }

}


int main(){
    vector<vector<int>> matrix = {
        {1,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,1}
    };
    set_matrix_zeros(matrix);
    for(vector<int> row: matrix){
        for(int val: row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}