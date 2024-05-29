#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void bellmanFord(int v, int e, int src, vector<int>& dist, const vector<vector<int>>& edges) {
    dist[src] = 0;
    for (int i = 0; i < v - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int j = 0; j < e; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "The graph contains a negative weight cycle." << endl;
            return;
        }
    }
}
