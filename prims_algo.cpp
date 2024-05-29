#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// unordered_map<int,list<pair<int,int>>> adj;

int prims(int v,vector<int>& path){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> visited(v,false);
    pq.push({0,0});
    int primWT = 0;
    while(!pq.empty()){
        pair<int,int> node;
        node = pq.top();
        pq.pop();

        if(visited[node.second]){
            continue;
        }

        primWT += node.first;
        path.push_back(node.second);
        visited[node.second] = true;

        for(auto j : adj[node.second]){
            if(!visited[j.second]){
                pq.push(j);
            }
        }
    }
    return primWT;
}

// void makeAdjDirected(int a,int b,int wt){
//     adj[a].push_back({wt,b});
// }
// void makeAdjUndireted(int a,int b,int wt){
//     adj[a].push_back({wt,b});
//     adj[b].push_back({wt,a});
// }
