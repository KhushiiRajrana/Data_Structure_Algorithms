#include<bits/stdc++.h>
using namespace std;
//recursive soln
class Solution {
public:
    int f(int i ,int j){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0 ){
            return 0;
        }
        int up=f(i-1,j);
        int left=f(i,j-1);

        return up+left;
    }
    int uniquePaths(int m, int n) {
        int ans= f(m-1,n-1);

        return ans;
        
    }
};
//memoization
class Solution {
public:
    int f(int i ,int j,vector<vector<int>> &dp){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0 ){
            return 0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        int up=f(i-1,j,dp);
        int left=f(i,j-1,dp);

        dp[i][j]=up+left;
        return dp[i][j];

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        int ans= f(m-1,n-1,dp);

        return ans;
        
    }
};
//tabulation
class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
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