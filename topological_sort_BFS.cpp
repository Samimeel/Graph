#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// to check cycle 

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

void findIndeg(vector<int>& indegree){
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
}

void topoSortBFS(int v,vector<int>& path){
    if(isCycle(v)){
        cout<<"Cycle is present in the graph so topological sort is not possible."<<endl;
        return ;
    }
    vector<int> indegree(v,0);
    findIndeg(indegree);
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        auto front = q.front();
        path.push_back(front);
        q.pop();
        for(auto f:adj[front]){
            indegree[f]--;
            if(indegree[f] == 0){
                q.push(f);
            }
        }
    }
}