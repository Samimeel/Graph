#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<pair<int,int>>> adj;

void dijkastra(int v,int src,vector<int>& dist){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src});

    dist[src] = 0;
    while(!pq.empty()){
        auto front = pq.top();
        pq.pop();
        
        for(auto j : adj[front.second]){
            if(dist[j.second] > dist[front.second] + j.first){
                dist[j.second] = dist[front.second] + j.first;
                pq.push(j);
            }
        }
    }
}