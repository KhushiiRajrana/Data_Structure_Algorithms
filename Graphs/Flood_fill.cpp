#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // colouring using bfs
        int m= image.size();
        int n=image[0].size();
        if(m==0){
            return {};
        }
        int dx[] ={1,-1 , 0 ,0 };
        int dy[]={0,0,-1,1};

        queue<pair<int,int>> q;
        q.push({sr,sc});
        int org = image[sr][sc];
        if(org == color) return image;

        while(!q.empty()){
            pair<int ,int> p= q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            image[x][y]=color;
            for(int i=0;i<4;i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if( nx>=0 && nx<m && ny>=0 && ny<n &&image[nx][ny]==org){
                    q.push({nx,ny });
                    image[nx][ny]=color;
                }
            }
            

        }

        return image;
        
    }
};