#include <iostream>
#include "Graph.hpp"
// #include "Algorithms.hpp"
// using ariel::Algorithms;

using namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{

    // 3x3 matrix that represents a connected graph.
    vector<vector<int> > graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    ariel::Graph g(graph, 3, false);
    g.loadGraph(graph,false); // Load the graph to the object.
    g.printGraph();     // Should print: "Graph with 3 vertices and 2 edges."

    return 0;
}