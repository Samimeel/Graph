#include<iostream>
#include<vector>
using namespace std;

bool dfs(int i,vector<bool>& visited,vector<int>& parent){
    visited[i] = true;
    for(auto j : adj[i]){
        if(parent[i] != j && visited[j]){
            return true;
        }
        else if(parent[i] != j){
            parent[j] = i;
            dfs(j,visited,parent);
        }
    }
    return false;
}

bool isCycle(int v){
    vector<bool> visited(v,false);
    vector<int> parent(v,-1);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(dfs(i,visited,parent)){
                return true;
            }
        }
    }
    return false;
}