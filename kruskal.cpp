#include<iostream>
#include<vector>
using namespace std;

void makeParent(int v,vector<int> &parent,vector<int> &rank){
    for(int i=0;i<v;i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(int node,vector<int> &parent){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent[node],parent);
}
void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
    if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else if(rank[v] > rank[u]){
        parent[u] = v;
    }
    else{
        parent[u] = v;
        rank[v]++;
    }
}
int minwt(int v,int e,vector<vector<int>> &edges,vector<int> &parent){
    sort(edges.begin(),edges.end(),comp);
    vector<int> rank(v);
    makeParent(v,parent,rank);
    int minWt = 0;
    for(int i=0;i<e;i++){
        int a = findParent(edges[i][0],parent);
        int b = findParent(edges[i][1],parent);
        int wt = edges[i][2];
        if(a != b){
            minWt += wt;
            unionSet(a,b,parent,rank);
        }
    }
    return minWt;
}
bool comp(vector<int> &a,vector<int> &b){
    return a[2] < b[2];
}