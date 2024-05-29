#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool bfs(int i,vector<bool>& visited,vector<int>& parent){
    queue<int> q;
    q.push(i);
    visited[i] = true;
    parent[i] = -1;
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        for(auto j : adj[front]){
            if(parent[front] != j && visited[j]){
                return true;
            }
            else if(parent[front] != j){
                q.push(j);
                parent[j] = front;
                visited[j] = true;
            }
        }
    }
    return false;
}

bool isCycle(int v){
    vector<bool> visited(v,false);
    vector<int> parent(v,-1);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(bfs(i,visited,parent)){
                return true;
            }
        }
    }
    return false;
}