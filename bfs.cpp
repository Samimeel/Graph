#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void findBFSpath(int v,int i,vector<int>& path,vector<bool>& visited){
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while(!q.empty()){
        auto front = q.front();
        path.push_back(front);
        q.pop();
        for(auto j:adj[front]){
            if(!visited[j]){
                q.push(j);
                visited[j] = true;
            }
        }
    }       
}
void bfs(int v,vector<int>& path){
    vector<bool>visited (v,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            findBFSpath(v,i,path,visited);
        }
    }
}

