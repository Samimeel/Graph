# Graph Algorithms

This repository contains implementations of various graph algorithms in C++. The algorithms include graph traversal, cycle detection, topological sorting, Minimum Spanning Tree (MST) construction, and shortest path finding.


## Introduction

Graph algorithms are fundamental in computer science, used to solve problems related to networking, optimization, scheduling, and more. This repository provides a comprehensive suite of graph algorithms implemented in C++ for educational purposes and practical usage.

## Algorithms

### Graph Traversal

1. **Depth-First Search (DFS)**
   - Implementation for traversing graphs using the DFS technique.
   - Useful for exploring all vertices and edges of a graph.

2. **Breadth-First Search (BFS)**
   - Implementation for traversing graphs using the BFS technique.
   - Useful for finding the shortest path in unweighted graphs.

### Cycle Detection

1. **Cycle Detection in Directed Graphs**
   - Using DFS.
   - Using BFS (Kahn's Algorithm).

2. **Cycle Detection in Undirected Graphs**
   - Using DFS.
   - Using BFS.

### Topological Sorting

- Implementation of topological sorting using both DFS and Kahn's Algorithm.
- Note : Topological sorting using DFS is same as DFS traversal.
- Applicable to Directed Acyclic Graphs (DAGs) for scheduling tasks.

### Minimum Spanning Tree (MST)

1. **Prim's Algorithm**
   - Implementation using a priority queue for finding the MST.
   
2. **Kruskal's Algorithm**
   - Implementation using the Disjoint Set Union (DSU) data structure.

### Shortest Path Finding

1. **Dijkstra's Algorithm**
   - Implementation using a priority queue for finding the shortest path in weighted graphs without negative weights.
   
2. **Bellman-Ford Algorithm**
   - Implementation for finding the shortest path in graphs with negative weights and detecting negative weight cycles.
