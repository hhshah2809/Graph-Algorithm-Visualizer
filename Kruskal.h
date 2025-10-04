#pragma once
#include "Algorithm.h"
#include "Graph.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Kruskal : public Algorithm {
private:
    Graph &g;
    vector<tuple<int,int,int>> mstEdges;
    int totalWeight = 0;

    vector<int> parent, rank;

    int find(int u){
        if(parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu == pv) return;
        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pu] > rank[pv]) parent[pv] = pu;
        else { parent[pv] = pu; rank[pu]++; }
    }

public:
    Kruskal(Graph &graph) : g(graph) {}

    void run() override {
        int V = g.getVertices();
        parent.resize(V);
        rank.resize(V, 0);
        for(int i=0;i<V;i++) parent[i]=i;

        vector<tuple<int,int,int>> edges;
        for(int u=0; u<V; u++){
            for(auto [v,w]: g.getNeighbors(u)){
                if(u < v) edges.push_back({w,u,v}); // avoid duplicate edges in undirected graph
            }
        }

        sort(edges.begin(), edges.end());

        for(auto [w,u,v]: edges){
            if(find(u) != find(v)){
                unite(u,v);
                mstEdges.push_back({u,v,w});
                totalWeight += w;
            }
        }
    }

    void displayResult() override {
        cout << "Kruskal MST Edges (u->v) and weights:\n";
        for(auto [u,v,w]: mstEdges){
            cout << u+1 << " -> " << v+1 << " weight: " << w << endl;
        }
        cout << "Total MST Weight: " << totalWeight << endl;
    }
};
