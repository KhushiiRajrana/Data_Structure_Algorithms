#include<bits/stdc++.h>
using namespace std;
//recursion
class Solution {
public:
    int f(int i,int j,vector<vector<int>>& matrix){
        int n=matrix.size();
        if (j < 0 || j >= n) return 1e9; 
        if(i==0){
            return matrix[0][j];
        }
        int straight=matrix[i][j]+f(i-1,j,matrix);
        int left_diag=matrix[i][j]+f(i-1,j-1,matrix);
        int right_diag=matrix[i][j]+f(i-1,j+1,matrix);

        return min(straight,min(left_diag,right_diag));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans = 1e9;

        // to try from all points in last row
        for(int i=0;i<n;i++){
            ans=min(ans,f(n-1,i,matrix));
        }
        return ans;
    
        
    }
};
//memoization
class Solution {
public:
    int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp ){
        int n=matrix.size();
        if (j < 0 || j >= n) return 1e9; 
        if(i==0){
            return matrix[0][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int straight=matrix[i][j]+f(i-1,j,matrix,dp);
        int left_diag=matrix[i][j]+f(i-1,j-1,matrix,dp);
        int right_diag=matrix[i][j]+f(i-1,j+1,matrix,dp);

        return dp[i][j]=min(straight,min(left_diag,right_diag));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans = 1e9;
        vector<vector<int>> dp(n,vector<int>(n,-1));

        // to try from all points in last row
        for(int i=0;i<n;i++){
            ans=min(ans,f(n-1,i,matrix,dp));
        }
        return ans;
    
        
    }
};
//tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans = 1e9;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0 ;j<n;j++){
                int straight=matrix[i][j]+dp[i-1][j];
                int left_diag=(j-1>=0) ? matrix[i][j]+dp[i-1][j-1]:1e9;
                int right_diag=(j+1 <n) ? matrix[i][j]+dp[i-1][j+1] : 1e9;
                dp[i][j]=min(straight,min(left_diag,right_diag));
            }
        }

        for(int i=0;i<n;i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
 
    }
};
//space optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans = 1e9;
        vector<int> prev(n);
        vector<int> curr(n);
        for(int j=0;j<n;j++){
            prev[j]=matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0 ;j<n;j++){
                int straight=matrix[i][j]+prev[j];
                int left_diag=(j-1>=0) ? matrix[i][j]+prev[j-1]:1e9;
                int right_diag=(j+1 <n) ? matrix[i][j]+prev[j+1] : 1e9;
                curr[j]=min(straight,min(left_diag,right_diag));
            }
            prev = curr;
        }

        for(int i=0;i<n;i++){
            ans = min(ans,prev[i]);
        }
        return ans;
 
    }
};