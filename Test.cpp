#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdexcept>
using namespace doctest;
using namespace ariel;
using namespace std;

// /***************** Testing Undirected graphs ********************/
// TEST_CASE("Test little graph undirected")
// {
//     ariel::Graph g(false);
//     vector<vector<int> > graph =
//         {{0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isConnected(g) == true);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == false);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "0");
//     vector<vector<int> > graph1 =
//         {{1}};
//     CHECK_THROWS(g.loadGraph(graph1));
// }

// TEST_CASE("Test without edges")
// {
//     ariel::Graph g(false);
//     vector<vector<int> > graph =
//         {{0, 0, 0},
//          {0, 0, 0},
//          {0, 0, 0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isConnected(g) == false);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == false);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");

//     vector<vector<int> > graph1 = {
//         {0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0},
//         {0, 0, 0, 0, 0}};
//     g.loadGraph(graph1);
//     CHECK(ariel::Algorithms::isConnected(g) == false);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == false);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");

//     vector<vector<int> > graph2 = {
//         {0, 0, 0, 0},
//         {0, 0, 0, 0},
//         {0, 0, 0, 0},
//         {0, 0, 0, 0}};
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::isConnected(g) == false);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == false);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");
// }
// TEST_CASE("Test isConnected")
// {
//     ariel::Graph g(false);
//     vector<vector<int> > graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isConnected(g) == true);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == false);
//     vector<vector<int> > graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::isConnected(g) == false);
// }

// TEST_CASE("Test shortestPath")
// {
//     ariel::Graph g(false);
//     vector<vector<int> > graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

//     vector<vector<int> > graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
// }
// TEST_CASE("Test isContainsCycle")
// {
//     ariel::Graph g(false);
//     vector<vector<int> > graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph);

//     CHECK(ariel::Algorithms::isContainsCycle(g) == false);

//     vector<vector<int> > graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//     g.loadGraph(graph2);

//     CHECK(ariel::Algorithms::isContainsCycle(g) == true);
// }
// TEST_CASE("Test isBipartite")
// {
//     ariel::Graph g(false);
//     vector<vector<int> > graph = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

//     vector<vector<int> > graph2 = {
//         {0, 1, 1, 0, 0},
//         {1, 0, 1, 0, 0},
//         {1, 1, 0, 1, 0},
//         {0, 0, 1, 0, 0},
//         {0, 0, 0, 0, 0}};
//     g.loadGraph(graph2);
//     CHECK(ariel::Algorithms::isBipartite(g) == "-1");

//     vector<vector<int> > graph3 = {
//         {0, 1, 2, 0, 0},
//         {1, 0, 3, 0, 0},
//         {2, 3, 0, 4, 0},
//         {0, 0, 4, 0, 5},
//         {0, 0, 0, 5, 0}};
//     g.loadGraph(graph3);
//     CHECK(ariel::Algorithms::isBipartite(g) == "-1");
// }
// TEST_CASE("Test invalid graph")
// {
//     ariel::Graph g(false);
//     vector<vector<int> > graph = {
//         {0, 1, 2, 0},
//         {1, 0, 3, 0},
//         {2, 3, 0, 4},
//         {0, 0, 4, 0},
//         {0, 0, 0, 5}};
//     CHECK_THROWS(g.loadGraph(graph));
// }
// TEST_CASE("Testing undirected negative cycle graphs")
// {
//     ariel::Graph g(false);
//     vector<vector<int> > graph5{
//         {0, 6, 7, 0, 0},
//         {6, 0, 8, -4, 0},
//         {7, 8, 0, 0, 5},
//         {0, -4, 0, 0, 7},
//         {0, 0, 5, 7, 0}};
//     g.loadGraph(graph5);
//     CHECK(ariel::Algorithms::isConnected(g) == true);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == true);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
//     CHECK(ariel::Algorithms::negativeCycle(g) == true); //"Negative cycle detected: 3->1->3"

//     vector<vector<int> > graph6 = {
//         {0, -1, 0, -1, 0},
//         {-1, 0, -1, 0, 0},
//         {0, -1, 0, 0, -1},
//         {-1, 0, 0, 0, -1},
//         {0, 0, -1, -1, 0}};
//     g.loadGraph(graph6);
//     CHECK(ariel::Algorithms::isConnected(g) == true);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == true);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
//     CHECK(ariel::Algorithms::negativeCycle(g) == true); //"Negative cycle detected: 4->2->4"
// }
// TEST_CASE("Testing large graph without weights edges")
// {
//     ariel::Graph g(false);
//     vector<vector<int> > graph8 = {
//         {0, 1, 1, 1, 0},
//         {1, 0, 1, 0, 1},
//         {1, 1, 0, 1, 1},
//         {1, 0, 1, 0, 0},
//         {0, 1, 1, 0, 0}};

//     g.loadGraph(graph8);
//     CHECK(ariel::Algorithms::isConnected(g) == true);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == true);
//     CHECK(ariel::Algorithms::isBipartite(g) == "-1");
//     CHECK(ariel::Algorithms::shortestPath(g, 3, 1) == "3->0->1");
// }
// TEST_CASE("Testing one edge undirected")
// {
//     ariel::Graph g(false);
//     vector<vector<int> > graph8 = {
//         {0, 1}, {1, 0}};
//     g.loadGraph(graph8);

//     CHECK(ariel::Algorithms::isConnected(g) == true);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == false);
//     CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={1}");
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "0->1");
// }

// /***************** Testing Directed graphs ********************/

// TEST_CASE("Testing directed unweighted graphs")
// {

//     ariel::Graph g(true);
//     vector<vector<int> > graph4 = {
//         {0, 1, 0},
//         {1, 0, 1},
//         {0, 1, 0}};
//     g.loadGraph(graph4);
//     CHECK(ariel::Algorithms::isConnected(g) == true);

//     CHECK(ariel::Algorithms::isContainsCycle(g) == true);

//     CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
//     CHECK(ariel::Algorithms::shortestPath(g, 2, 0) == "2->1->0");
// }

// TEST_CASE("Test shortestPath for DirectedGraph weighted non-negative")
// {
//     Graph g(true);
//     vector<vector<int> > graph = {
//         {0, 3, 0},
//         {1, 0, 5},
//         {0, 0, 0}};
//     g.loadGraph(graph);
//     CHECK(Algorithms::shortestPath(g, 0, 1) == "0->1");
//     CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");
//     CHECK(Algorithms::shortestPath(g, 1, 2) == "1->2");
//     CHECK(Algorithms::shortestPath(g, 2, 0) == "-1");
//     CHECK(Algorithms::shortestPath(g, 0, 0) == "0");
// }
// TEST_CASE("little graph directed")
// {
//     ariel::Graph g(true);
//     vector<vector<int> > graph =
//         {{0}};
//     g.loadGraph(graph);
//     CHECK(ariel::Algorithms::isConnected(g) == true);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == false);
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 0) == "0");
//     vector<vector<int> > graph1 =
//         {{1}};
//     CHECK_THROWS(g.loadGraph(graph1));
// }
// ///////////////////////////////////////////////////
// TEST_CASE("Test empty graph")
// {
//     Graph g(false);

//     // empty graph
//     vector<vector<int> > emptyGraph = {};
//     g.loadGraph(emptyGraph);
//     CHECK(Algorithms::negativeCycle(g) == false);
//     CHECK(ariel::Algorithms::isConnected(g) == true);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == false);
//     CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, 0));
//     CHECK(ariel::Algorithms::isBipartite(g) == "-1");
// }
// TEST_CASE("Testing one edge directed")
// {
//     ariel::Graph g(true);
//     vector<vector<int> > graph8 = {
//         {0, 1}, {1, 0}};
//     g.loadGraph(graph8);

//     CHECK(ariel::Algorithms::isConnected(g) == true);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == true);
//     CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={1}");
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "0->1");
//     CHECK(ariel::Algorithms::shortestPath(g, 1, 0) == "1->0");
// }
// TEST_CASE("Testing isConnected directed")
// {
//     ariel::Graph g(true);
//     vector<vector<int> > graph8 = {
//         {0, 1},
//         {0, 0}};
//     g.loadGraph(graph8);
//     CHECK(ariel::Algorithms::isConnected(g) == false);
//     CHECK(ariel::Algorithms::isContainsCycle(g) == false);
//     CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={1}");
//     CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "0->1");
//     CHECK(ariel::Algorithms::shortestPath(g, 1, 0) == "-1");
// }




TEST_CASE("Testing large graph directed")
{
    ariel::Graph g(true);

  vector<vector<int>> graph7 = {
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0}};
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4, 5}, B={1, 6, 3}");
    CHECK(ariel::Algorithms::shortestPath(g, 6, 4) == "6->0->1->2->3->4");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 4) == "1->2->3->4");
}
