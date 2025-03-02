#include<iostream>
#include<vector>
using namespace std;

void set_matrix_zeros(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector <int> row(n,0);
    vector<int> col(m,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]||col[j]){
                matrix[i][j] = 0;
            }
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