#include<iostream>
#include<vector>
using namespace std;


bool dfs(int i,vector<bool>& dfsVisited,vector<bool>& visited){
    if(dfsVisited[i]){
        return true;
    }
    if(visited[i]){
        return false;
    }
    visited[i] = true;
    dfsVisited[i] = true;
    for(auto j : adj[i]){
        if(dfs(j,dfsVisited,visited)){
            return true;
        }
    }
    dfsVisited[i] = false;
    return false;
}

bool isCycle(int v){
    vector<bool> dfsVisited(v,false);
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(dfs(i,dfsVisited,visited)){
                return true;
                
            }
        }
    }
    return false;
}