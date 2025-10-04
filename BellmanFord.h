#pragma once
#include "Algorithm.h"

class BellmanFord : public Algorithm {
private:
    Graph &g;
    vector<int> dist;

public:
    BellmanFord(Graph &graph) : g(graph), dist(graph.getVertices(), INT_MAX) {}

    void run() override {
        int V = g.getVertices();
        dist[0] = 0;

        for(int i=1;i<V;i++){
            for(int u=0;u<V;u++){
                for(auto [v,w]: g.getNeighbors(u)){
                    if(dist[u]!=INT_MAX && dist[v]>dist[u]+w) dist[v]=dist[u]+w;
                }
            }
        }
    }

    void displayResult() override {
        cout << "Bellman-Ford Shortest Distances from Vertex 0:\n";
        for(int i=0;i<dist.size();i++) cout << i << " : " << dist[i] << endl;
    }
};
