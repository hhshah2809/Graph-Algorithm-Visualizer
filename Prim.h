#pragma once
#include "Algorithm.h"
#include "Graph.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Prim : public Algorithm {
private:
    Graph &g;
    vector<pair<int,int>> mstEdges;
    int totalWeight = 0;

public:
    Prim(Graph &graph) : g(graph) {}

    void run() override {
        int V = g.getVertices();
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        key[0] = 0;
        for(int count=0; count<V-1; count++){
            int u = -1;
            for(int i=0; i<V; i++)
                if(!inMST[i] && (u==-1 || key[i]<key[u])) u = i;

            inMST[u] = true;

            for(auto [v,w]: g.getNeighbors(u)){
                if(!inMST[v] && w < key[v]){
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        for(int v=1; v<V; v++){
            if(parent[v] != -1){
                mstEdges.push_back({parent[v], v});
                totalWeight += key[v];
            }
        }
    }

    void displayResult() override {
        cout << "Prim MST Edges (u->v) and weights:\n";
        for(auto [u,v]: mstEdges){
            for(auto [x,w]: g.getNeighbors(u)){
                if(x == v){
                    cout << u+1 << " -> " << v+1 << " weight: " << w << endl;
                    break;
                }
            }
        }
        cout << "Total MST Weight: " << totalWeight << endl;
    }
};
