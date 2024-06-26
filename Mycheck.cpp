#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"
// using ariel::Algorithms;

using namespace ariel;
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
//     cout << "graph number 1"<<endl;
//     // 3x3 matrix that represents a connected graph.
//     vector<vector<int> > graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     ariel::Graph g( false);
//     g.loadGraph(graph); // Load the graph to the object.
//     g.printGraph();     // Should print: "Graph with 3 vertices and 2 edges."
//     cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
//     cout << Algorithms::isConnected(g) << endl; // Should print: true  1

// printf("*********************************************************************************************************\n");

//     cout << "graph number 2"<<endl;

//      // 5x5 matrix that represents a non-connected graph with a cycle.
//     vector<vector<int> > graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};

//     g.loadGraph(graph2); // Load the graph to the object.

//     g.printGraph();                                    // Should print: "Graph with 5 vertices and 4 edges."
//     cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
//      cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
// //     // cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
// //     // cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).

// printf("*********************************************************************************************************\n");

// //     cout << "graph number 3"<<endl;

// // // 5x4 matrix that reprsents invalid graph.
// //     vector<vector<int>> graph4 = {
// //         {0, 1, 2, 0},
// //         {1, 0, 3, 0},
// //         {2, 3, 0, 4},
// //         {0, 0, 4, 0},
// //         {0, 0, 0, 5}};
    
    
// //           try
// //     {
// //         g.loadGraph(graph4); // Load the graph to the object.
// //     }
// //     catch (const std::invalid_argument &e)
// //     {
// //         cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
// //     }
// printf("*********************************************************************************************************\n");

// cout<<"graph number 4"<<endl;
// vector<vector<int> > graph4 = {
//         {0, 4, 0},
//         {4, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph4); // Load the graph to the object.
//     cout << Algorithms::isContainsCycle(g) << endl;//Should print: -1
//     cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
// cout<<"graph number 5"<<endl;
// printf("*********************************************************************************************************\n");

//  vector<vector<int>> graph5 = {
//         {0, 4, 0, 0, 0},
//         {0, 0, 8, 0, 0},
//         {0, 0, 0, 7, 0},
//         {0, 0, 0, 0, 2},
//         {2, 0, 0, 0, 0}
//     };
//     g.loadGraph(graph5); // Load the graph to the object.
// cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->1->2.


// printf("*********************************************************************************************************\n");

// cout<<"graph number 6"<<endl;
// vector<vector<int>> graph6 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//          g.loadGraph(graph6);
//          cout << Algorithms::isContainsCycle(g)<< endl;
printf("*********************************************************************************************************\n");
cout<<"graph number 7"<<endl;
    ariel::Graph g1(true);

//directed graph     TODOOOOOOOOOOOOOOOOOOOO
    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph7 = {
        {0, 1, 0, 3, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};

    g1.loadGraph(graph7); // Load the graph to the object.

    g1.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
    cout << Algorithms::isConnected(g1) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g1, 0, 4) << endl; // Should print: 0->3->4.
   // cout << Algorithms::isContainsCycle(g1) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g1) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."




    return 0;
}