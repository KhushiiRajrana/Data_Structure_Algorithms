#include<bits/stdc++.h>
using namespace std;
//memoization
class Solution {
public:
int f(int i ,int j,vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0 ){
            return 0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        int up=f(i-1,j,dp,obstacleGrid);
        int left=f(i,j-1,dp,obstacleGrid);

        dp[i][j]=up+left;
        return dp[i][j];

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int ans= f(m-1,n-1,dp,obstacleGrid);

        return ans;
        
    }
};
//tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
         vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1 ){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else{
                    int up= (i>0) ?dp[i-1][j] : 0;
                    int left=(j>0) ?dp[i][j-1]:0;

                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};