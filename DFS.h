#pragma once
#include "Algorithm.h"

class DFS : public Algorithm {
private:
    Graph &g;
    vector<int> traversal;
    vector<bool> visited;

    void dfsUtil(int u){
        visited[u] = true;
        traversal.push_back(u);
        for(auto [v,w] : g.getNeighbors(u)){
            if(!visited[v]) dfsUtil(v);
        }
    }

public:
    DFS(Graph &graph) : g(graph), visited(graph.getVertices(), false) {}

    void run() override { dfsUtil(0); }

    void displayResult() override {
        cout << "DFS Traversal: ";
        for(int v : traversal) cout << v << " ";
        cout << endl;
    }
};
