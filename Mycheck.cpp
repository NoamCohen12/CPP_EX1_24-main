#include <iostream>
#include "Graph.hpp"
 #include "Algorithms.hpp"
// using ariel::Algorithms;

using namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    cout << "graph number 1"<<endl;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int> > graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    ariel::Graph g(graph, 3, false);
    g.loadGraph(graph); // Load the graph to the object.
    g.printGraph();     // Should print: "Graph with 3 vertices and 2 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.





    cout << "graph number 2"<<endl;

     // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int> > graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
     cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
//     // cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
//     // cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).

//     cout << "graph number 3"<<endl;

// // 5x4 matrix that reprsents invalid graph.
//     vector<vector<int>> graph4 = {
//         {0, 1, 2, 0},
//         {1, 0, 3, 0},
//         {2, 3, 0, 4},
//         {0, 0, 4, 0},
//         {0, 0, 0, 5}};
    
    
//           try
//     {
//         g.loadGraph(graph4); // Load the graph to the object.
//     }
//     catch (const std::invalid_argument &e)
//     {
//         cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
//     }
cout<<"graph number four"<<endl;
vector<vector<int> > graph4 = {
        {0, 4, 1},
        {4, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph4); // Load the graph to the object.
    cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
cout<<"graph number five"<<endl;

 vector<vector<int>> graph5 = {
        {0, 4, 0, 0, 0},
        {0, 0, 8, 0, 0},
        {0, 0, 0, 7, 0},
        {0, 0, 0, 0, 2},
        {2, 0, 0, 0, 0}
    };
    g.loadGraph(graph5); // Load the graph to the object.
cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->1->2.


    return 0;
}