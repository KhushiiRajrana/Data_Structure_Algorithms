#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col= matrix[0].size();
        vector<bool> rows(row,false);
        vector<bool> cols(col,false);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    rows[i]=true;
                    cols[j]=true;
                }
            }
        }
        // now make the comp row zero whose value is true in rows array
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(rows[i]){
                    matrix[i][j]=0;
                }
            }
        }

        // now make that column zero whose value is true in cols array

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(cols[j]){
                    matrix[i][j]=0;
                }
            }
        }

        
    }
};