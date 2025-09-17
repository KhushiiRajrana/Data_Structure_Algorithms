#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, 
          vector<vector<vector<int>>> &dp) {
        
        // Out of bounds
        if (j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) return -1e8;

        // Base case: last row
        if (i == r - 1) {
            if (j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        // Already computed
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e8;

        // Explore all 9 possibilities
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int value = 0;
                if (j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];

                value += f(i + 1, j1 + dj1, j2 + dj2, r, c, grid, dp);
                maxi = max(maxi, value);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        return f(0, 0, c - 1, r, c, grid, dp);
    }
};

//tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        // 3D DP table: dp[row][j1][j2]
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

        // Base case: last row
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                if (j1 == j2) dp[r-1][j1][j2] = grid[r-1][j1];
                else dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
            }
        }

        // Fill DP table bottom-up
        for (int i = r - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < c; j1++) {
                for (int j2 = 0; j2 < c; j2++) {

                    int maxi = -1e8;
                    // Explore all 9 possibilities
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int value = 0;
                            if (j1 == j2) value = grid[i][j1];
                            else value = grid[i][j1] + grid[i][j2];

                            if (j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c) {
                                value += dp[i+1][j1+dj1][j2+dj2];
                            } else {
                                value += -1e8; // invalid move
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        // Start from (0,0) and (0,c-1)
        return dp[0][0][c-1];
    }
};

