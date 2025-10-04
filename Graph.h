#pragma once
#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V;
    bool weighted;
    bool directed;
    vector<vector<pair<int,int>>> adj;

public:
    Graph(int vertices, bool isWeighted=false, bool isDirected=false) {
        V = vertices;
        weighted = isWeighted;
        directed = isDirected;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w=1) {
        adj[u].push_back({v, w});
        if(!directed) adj[v].push_back({u, w});
    }

    vector<pair<int,int>> getNeighbors(int v) { return adj[v]; }
    int getVertices() { return V; }
    bool isWeighted() { return weighted; }
    bool isDirected() { return directed; }
};
