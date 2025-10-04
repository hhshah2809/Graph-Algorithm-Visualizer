#pragma once
#include "Algorithm.h"

class BFS : public Algorithm {
private:
    Graph &g;
    vector<int> traversal;

public:
    BFS(Graph &graph) : g(graph) {}

    void run() override {
        int V = g.getVertices();
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(0); visited[0] = true;

        while(!q.empty()){
            int u = q.front(); q.pop();
            traversal.push_back(u);
            for(auto [v,w] : g.getNeighbors(u)){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void displayResult() override {
        cout << "BFS Traversal: ";
        for(int v : traversal) cout << v << " ";
        cout << endl;
    }
};
