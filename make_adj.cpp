#include<iostream>
#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int>> adj;
void makeAdjDirected(int a,int b){
    adj[a].push_back(b);
}
void makeAdjUndireted(int a,int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void printAdj(){
    for(auto i:adj){
        cout<<i.first<<" -> ";
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}