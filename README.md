# 📊 Graph Algorithms Simulator

A **menu-driven C++ project** that demonstrates various **Graph Algorithms** with an object-oriented design.
This project is designed for **learning, practicing, and showcasing DSA concepts** (specially Graph Algorithms) in interviews and assignments.

---

## ✨ Features

✔️ **Object-Oriented Design** – `Graph` class + `Algorithm` base class with polymorphism
✔️ **Menu-Driven Interface** – run any algorithm interactively
✔️ **Supports Directed & Undirected Graphs**
✔️ **Supports Weighted & Unweighted Graphs**
✔️ Easy to extend – new algorithms can be added by inheriting `Algorithm` class

---

## 📌 Implemented Algorithms

1. **Graph Traversal**

   * BFS (Breadth-First Search)
   * DFS (Depth-First Search)

2. **Shortest Path**

   * Dijkstra’s Algorithm
   * Bellman-Ford Algorithm
   * Floyd-Warshall Algorithm

3. **Minimum Spanning Tree (MST)**

   * Kruskal’s Algorithm
   * Prim’s Algorithm

4. **Graph Coloring**

   * Backtracking-based coloring (exam scheduling / map coloring)

5. **Graph Ordering**

   * Topological Sort

6. **Cycle Detection**

   * Works for **both Directed & Undirected** graphs

---

## 🖥️ How to Run

### 1. Clone the repository

```bash
git clone https://github.com/your-username/Graph-Algorithms-Visualizer.git
cd "Graph Algorithms Visualizer"   # or cd Graph-Algorithms-Visualizer
```

### 2. Compile the project

If you’re using **g++**:

```bash
g++ -std=c++17 main.cpp -o GraphSimulator
```

(If you have multiple `.cpp` files, compile them all:

```bash
g++ main.cpp Graph.cpp BFS.cpp DFS.cpp Dijkstra.cpp BellmanFord.cpp FloydWarshall.cpp Kruskal.cpp Prim.cpp Coloring.cpp TopologicalSort.cpp CycleDetection.cpp -o graph_sim
```

)

### 3. Run the program

```bash
./graph_sim
```

---

## 📚 Usage Example

1. Enter number of vertices & edges

2. Choose whether graph is **directed** and/or **weighted**

3. Input edges (with weights if weighted)

4. Select algorithm from menu:

   ```
   ----- Graph Algorithm Simulator -----
   1. BFS
   2. DFS
   3. Dijkstra
   4. Bellman-Ford
   5. Floyd-Warshall
   6. Kruskal
   7. Prim
   8. Graph Coloring
   9. Topological Sort
   10. Cycle Detection
   11. Exit
   ```

5. See results directly on console.

---

## 🏗️ Project Structure

```
📂 Graph-Algorithms-Visualizer
├── main.cpp
├── Graph.h / Graph.cpp
├── Algorithm.h
├── BFS.h / BFS.cpp
├── DFS.h / DFS.cpp
├── Dijkstra.h / Dijkstra.cpp
├── BellmanFord.h / BellmanFord.cpp
├── FloydWarshall.h / FloydWarshall.cpp
├── Kruskal.h / Kruskal.cpp
├── Prim.h / Prim.cpp
├── Coloring.h / Coloring.cpp
├── TopologicalSort.h / TopologicalSort.cpp
├── CycleDetection.h / CycleDetection.cpp
└── README.md
```

---

## 🧑‍💻 OOP Concepts Used

* **Encapsulation** → Graph details hidden in `Graph` class
* **Inheritance** → Every algorithm inherits from `Algorithm` base class
* **Polymorphism** → `run()` and `displayResult()` methods overridden in each algorithm
* **Abstraction** → User interacts via simple menu, internal details are abstracted

---

## 🎯 Why This Project?

* Great way to **revise DSA**
* Shows **problem-solving + coding + OOP skills**
* Perfect to discuss in **interviews & resumes**
* Easy for others to clone and run

---

## 🛠️ Requirements

* C++11 or above
* g++ compiler / MinGW / Visual Studio Code with C++ extension

---

## 📖 Future Improvements

* Add **visualization (GUI / web)** for better learning
* Add more algorithms like **Johnson’s Algorithm, Strongly Connected Components, Bridges & Articulation Points**
* Export results to files

---

## 👨‍💻 Author

* **Your Name** (Het Shah)
* 📧 Contact: [hetshah23578@gmail.com](mailto:hetshah23578@gmail.com)
* 🌐 GitHub: [hhshah2809](https://github.com/hhshah2809)

---

⭐ If you like this project, give it a star on GitHub!
