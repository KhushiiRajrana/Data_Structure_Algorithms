#include<bits/stdc++.h>
using namespace std;
//memoization
class Solution {
public:
   int  f(int i,int j,int n,vector<vector<int>> &dp,vector<vector<int>> &triangle){
        if(i==n-1){
            return triangle[n-1][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int down = triangle[i][j]+f(i+1,j,n,dp,triangle);
        int diagonal = triangle[i][j]+f(i+1,j+1,n,dp,triangle);

        return dp[i][j] = min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,n,dp,triangle);
        
    }
};
//tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: last row
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        // Fill from bottom to top
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0];
    }
};
