#pragma once
#include "Algorithm.h"
#include "Graph.h"
#include <vector>
#include <iostream>
using namespace std;

class CycleDetection : public Algorithm {
private:
    Graph &g;
    bool hasCycle;

    // For undirected graph
    vector<bool> visited;
    bool dfsUndirected(int v, int parent) {
        visited[v] = true;
        for (auto [u, w] : g.getNeighbors(v)) {
            if (!visited[u]) {
                if (dfsUndirected(u, v)) return true;
            }
            else if (u != parent) {
                return true; // back-edge in undirected
            }
        }
        return false;
    }

    // For directed graph
    vector<bool> visitedDir, recStack;
    bool dfsDirected(int v) {
        visitedDir[v] = true;
        recStack[v] = true;

        for (auto [u, w] : g.getNeighbors(v)) {
            if (!visitedDir[u] && dfsDirected(u)) return true;
            else if (recStack[u]) return true; // back-edge in directed
        }

        recStack[v] = false;
        return false;
    }

public:
    CycleDetection(Graph &graph) : g(graph), hasCycle(false) {}

    void run() override {
        int V = g.getVertices();
        hasCycle = false;

        if (g.isDirected()) {  
            // Directed cycle check
            visitedDir.assign(V, false);
            recStack.assign(V, false);
            for (int i = 0; i < V; i++) {
                if (!visitedDir[i] && dfsDirected(i)) {
                    hasCycle = true;
                    break;
                }
            }
        } else {  
            // Undirected cycle check
            visited.assign(V, false);
            for (int i = 0; i < V; i++) {
                if (!visited[i] && dfsUndirected(i, -1)) {
                    hasCycle = true;
                    break;
                }
            }
        }
    }

    void displayResult() override {
        if (g.isDirected()) {
            if (hasCycle) cout << "Directed Graph has a cycle.\n";
            else cout << "Directed Graph has no cycle.\n";
        } else {
            if (hasCycle) cout << "Undirected Graph has a cycle.\n";
            else cout << "Undirected Graph has no cycle.\n";
        }
    }
};
