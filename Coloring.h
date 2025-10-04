#pragma once
#include "Algorithm.h"
#include "Graph.h"
#include <vector>
#include <iostream>
using namespace std;

class Coloring : public Algorithm {
private:
    Graph &g;
    vector<int> colors;
    int m;  // maximum number of colors allowed
    bool solved;

    bool isSafe(int v, int c) {
        for (auto [u, w] : g.getNeighbors(v)) {
            if (colors[u] == c) return false;
        }
        return true;
    }

    bool colorUtil(int v) {
        int V = g.getVertices();
        if (v == V) return true;

        for (int c = 0; c < m; c++) {
            if (isSafe(v, c)) {
                colors[v] = c;
                if (colorUtil(v + 1)) return true;
                colors[v] = -1; // backtrack
            }
        }
        return false;
    }

public:
    Coloring(Graph &graph, int maxColors = 4) : g(graph), m(maxColors), solved(false) {
        colors.assign(graph.getVertices(), -1);
    }

    void run() override {
        solved = colorUtil(0);
    }

    void displayResult() override {
        if (!solved) {
            cout << "No solution exists with " << m << " colors.\n";
            return;
        }
        cout << "Graph Coloring (Backtracking):\n";
        for (int i = 0; i < colors.size(); i++) {
            cout << "Vertex " << i << " -> Color " << colors[i] << endl;
        }
    }
};
