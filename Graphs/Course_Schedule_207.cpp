#include<bits/stdc++.h>
using namespace std;
// topologocal sort question
// create adj list
//find indegree of every node
// push all nodes with indegree 0 in queue
// do bfs and keep on reducing indegree of adjacent nodes
// if indegree becomes 0 push it in queue
// at last if topo sort size == numCourses return true else false

bool canfinish(int numCourses , vector<vector<int>>& prerequisites){
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses,0);
    for(auto &p : prerequisites){
        int u=p[1];
        int v=p[0];
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int count =0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;

        for(int neigh : adj[node]){
            indegree[neigh]--;
            if(indegree[neigh]==0){
                q.push(neigh);
            }
        }
    }

    return count == numCourses;
}
  