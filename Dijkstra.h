#pragma once
#include "Algorithm.h"

class Dijkstra : public Algorithm {
private:
    Graph &g;
    vector<int> dist;

public:
    Dijkstra(Graph &graph) : g(graph), dist(graph.getVertices(), INT_MAX) {}

    void run() override {
        int V = g.getVertices();
        dist[0] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0}); // {dist, vertex}

        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            if(d > dist[u]) continue;
            for(auto [v,w] : g.getNeighbors(u)){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    void displayResult() override {
        cout << "Dijkstra Shortest Distances from Vertex 0:\n";
        for(int i=0;i<dist.size();i++) cout << i << " : " << dist[i] << endl;
    }
};
