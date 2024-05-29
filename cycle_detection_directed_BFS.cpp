#include<iostream>
#include<vector>
using namespace std;

void findIndeg(int v,vector<int>& indegree){
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
}

bool isCycle(int v){
    vector<int> indegree(v,0);
    findIndeg(v,indegree);
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    int count = 0;
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        count++;
        for(auto j:adj[front]){
            indegree[j]--;
            if(indegree[j] == 0){
                q.push(j);
            }
        }
    }
    if(count == v){
        return false;
    }
    else{
        return true;
    }
}