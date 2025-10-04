#pragma once
#include "Algorithm.h"
#include "Graph.h"
#include <vector>
#include <queue>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class FloydWarshall : public Algorithm {
private:
    Graph &g;
    vector<vector<int>> dist;

public:
    FloydWarshall(Graph &graph) : g(graph) {
        int V = g.getVertices();
        dist.resize(V, vector<int>(V, INT_MAX));
        for(int i=0;i<V;i++) dist[i][i] = 0;
        for(int u=0;u<V;u++){
            for(auto [v,w]: g.getNeighbors(u)){
                dist[u][v] = w;
            }
        }
    }

    void run() override {
        int V = g.getVertices();
        for(int k=0;k<V;k++)
            for(int i=0;i<V;i++)
                for(int j=0;j<V;j++)
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][j]>dist[i][k]+dist[k][j])
                        dist[i][j] = dist[i][k]+dist[k][j];
    }

    void displayResult() override {
        cout << "Floyd-Warshall All-Pairs Shortest Distances:\n";
        int V = g.getVertices();
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][j]==INT_MAX) cout << "INF ";
                else cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};
