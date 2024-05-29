#include<iostream>
#include<vector>
using namespace std;

void dfsFindPath(int v,int i,vector<bool>& visited,stack<int>& path){
    visited[i] = true;
    for(auto j:adj[i]){
        if(!visited[j]){
            dfsFindPath(v,j,visited,path);
        }
    }
    path.push(i);
}
void dfs(int v,stack<int>& path){
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfsFindPath(v,i,visited,path);
        }
    }
}