#include <bits/stdc++.h>
using namespace std;
// crux of th eproem is to find th element and considering the whole 2d matrix as a singl esorted array 
// since we have to find th element in termf of matrix[i][j]
// e = row*col;
// mid will    simply s+(e-s)/2
// required element will  matrix[mid/col][mid%col]
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0;
        int row=matrix.size();
        int col=matrix[0].size();
        int e=row*col-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int element=matrix[mid/col][mid%col];
            if(target==element){
                return true;
            }
            else if(target>element){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }

        return false;
    }
};