#pragma once
#include "Algorithm.h"
#include "Graph.h"
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class TopologicalSort : public Algorithm {
private:
    Graph &g;
    vector<int> result;
    vector<bool> visited;

    void dfs(int v, stack<int> &st) {
        visited[v] = true;
        for (auto [u, w] : g.getNeighbors(v)) {
            if (!visited[u]) dfs(u, st);
        }
        st.push(v);
    }

public:
    TopologicalSort(Graph &graph) : g(graph) {}

    void run() override {
        int V = g.getVertices();
        visited.assign(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) dfs(i, st);
        }

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
    }

    void displayResult() override {
        cout << "Topological Order: ";
        for (int v : result) cout << v << " ";
        cout << endl;
    }
};
