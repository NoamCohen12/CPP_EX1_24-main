# CPP_EX1_24

The project implements in C++   
and deals with graphs and various algorithms on them


## Author
Noam Cohen 

Email: noam12345002@gmail.com
 


## Graph
The graph is represented as a 2D adjacency matrix.

My code refers to 2 graphs types:

1.directed graph

2.undirected graph

also refers to 3 casses:

1.without weight.

2.with positive weight.

3.with negative weight.



## Main Classes

1.**Graph.cpp**

2.**Alogrithms.cpp**



### Graph.cpp:
        
**loadGraph**: Loads a graph from a provided 2D vector representing its adjacency matrix.

**printGraph**: Prints the contents of the graph.

**graph_type**: Determines the type of the graph (e.g., directed, undirected) based on its adjacency matrix.

**getSize**: Returns the number of vertices in the graph.

**get_matrix**: Returns the adjacency matrix of the graph.

**isDirectedG**: Checks if the graph is directed or not.

**get_type_graph**: Gets the type of the graph.

**getTranspose**: Returns the transpose of the graph.

**add_opposite_edges**: Adds opposite edges to the graph, effectively converting it into an undirected graph.



### Alogrithms.cpp:

**isConnected:** This function checks whether a graph is connected.
For undirected graphs, it uses **BFS** (breadth-first search) to traverse the graph and determine if all vertices are reachable from each other. 
For directed graphs, it checks connectivity in both directions by using **BFS** on the original graph and its transpose by **getTranspose**.

**shortestPath:** Calculates the shortest path between two vertices in a graph.
 It handles different types of graphs and edge weights. Depending on the type of graph (whether it's undirected, weighted, etc.),
  1. **BFS** (for unweighted graphs).
  2. **Dijkstra's** algorithm (for graphs with positive edge weights).
  3. **Bellman-Ford** algorithm (for graphs with negative edge weights).

**isContainsCycle:** Determines if a graph contains any cycle by **DFS** algorithm. It delegates the cycle detection to specialized functions depending on whether the graph is directed or undirected. If a cycle is found, the function returns true; otherwise, it returns false.

**isBipartite:** Checks if a graph is bipartite, meaning its vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent. It applies a two-coloring algorithm based on **BFS** to determine if such a division is possible.
 Depending on the graph's type:
1.directed grpah - add **oposite edges** and work with **two-coloring** algorithm based on **BFS**.
2.undirected grpah - work with two-coloring algorithm based on **BFS**.


**negativeCycle:** Determines if a graph contains a negative weight cycle.
 It applies the **Bellman-Ford** algorithm, which is capable of detecting negative cycles. If a negative cycle is found, the function returns true; otherwise, it returns false.



## Tests

My code was checked with many tests with the "make test" command.
also checked with "make tidy" for Correct design of code in C++
and "make valgrind" To check for memory leaks.

## Main Algorithms
-bool isConnected(Graph &graph)

-string shortestPath(Graph &graph, size_t start, size_t end)

-bool isContainsCycle(Graph &graph);

-string isBipartite(Graph &graph);

-bool negativeCycle(Graph &graph);
