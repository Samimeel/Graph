#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
class Graph{
    public:
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
};

int main(){
    int v,e;
    cout<<"Enter number of vertex : ";
    cin>>v;
    
    cout<<"Enter number of edges : ";
    cin>>e;
    Graph g;

    int dir;
    cout<<"Press 1 if graph is direct, else press 0"<<endl;
    cin>>dir;

    for(int i=0;i<e;i++){
        int a,b;
        if(i == 0){
            cout<<"Enter vertices of 1st edge : "<<endl;
        }
        else if(i == 1){
            cout<<"Enter vertices of 2nd edge : "<<endl;
        }
        else if(i == 2){
            cout<<"Enter vertices of 3rd edge : "<<endl;
        }
        else{
            cout<<"Enter vertices of "<<i+1<<"th edge : "<<endl;
        }
        cin>>a>>b;
        if(dir){
            g.makeAdjDirected(a,b);
        }
        else{
            g.makeAdjUndireted(a,b);
        }
    }
    g.printAdj();
    return 0;
}