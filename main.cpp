#include <iostream>
#include <vector>
using namespace std;
#include "Graph.h"
#include "Algorithm.h"
#include "BFS.h"
#include "DFS.h"
#include "Dijkstra.h"
#include "BellmanFord.h"
#include "FloydWarshall.h"
#include "Kruskal.h"
#include "Prim.h"
#include "Coloring.h"
#include "CycleDetection.h"
#include "TopologicalSort.h"
using namespace std;
// include TopologicalSort.h, CycleDetection.h

int main() {
    int V; bool weighted, directed;
    cout << "Enter number of vertices: "; cin >> V;
    cout << "Weighted graph? (1-yes, 0-no): "; cin >> weighted;
    cout << "Directed graph? (1-yes, 0-no): "; cin >> directed;

    Graph g(V, weighted, directed);

    int E; cout << "Enter number of edges: "; cin >> E;
    for(int i=0;i<E;i++){
        int u,v,w=1;
        cout << "Edge " << i+1 << " (u v"; if(weighted) cout<<" w"; cout << "): ";
        cin >> u >> v;
        if(weighted) cin >> w;
        g.addEdge(u,v,w);
    }

    int choice;
    do {
        cout << "\n----- Graph Algorithm Simulator -----\n";
        cout << "1. BFS\n2. DFS\n3. Dijkstra\n4. Bellman-Ford\n5. Floyd-Warshall\n";
        cout << "6. Kruskal\n7. Prim\n8. Graph Coloring\n9. Topological Sort\n10. Cycle Detection\n11. Exit\n";
        cout << "Enter choice: "; cin >> choice;

        Algorithm *algo=nullptr;
        switch(choice){
            case 1: algo=new BFS(g); break;
            case 2: algo=new DFS(g); break;
            case 3: if(!weighted){cout<<"Dijkstra needs weighted graph!\n"; continue;} algo=new Dijkstra(g); break;
            case 4: if(!weighted){cout<<"Bellman-Ford needs weighted graph!\n"; continue;} algo=new BellmanFord(g); break;
            case 5: if(!weighted){cout<<"Floyd-Warshall needs weighted graph!\n"; continue;} algo=new FloydWarshall(g); break;
            case 6: if(!weighted){cout<<"Kruskal needs weighted graph!\n"; continue;} algo=new Kruskal(g); break;
            case 7: if(!weighted){cout<<"Prim needs weighted graph!\n"; continue;} algo=new Prim(g); break;
            case 8: algo=new Coloring(g); break;
            case 9: algo=new TopologicalSort(g); break;
            case 10: algo=new CycleDetection(g); break;
            case 11: break;
            default: cout << "Invalid choice\n"; continue;
        }

        if(algo){
            algo->run();
            algo->displayResult();
            delete algo;
        }
    } while(choice!=11);

    return 0;
}
