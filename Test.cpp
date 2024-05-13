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

/***************** Testing Undirected graphs ********************/

TEST_CASE("empty graph")
{
    ariel::Graph g(false);
    vector<vector<int> > graph =
        {{0, 0, 0},
         {0, 0, 0},
         {0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == 0);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");

    vector<vector<int> > graph1 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(g) == 0);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");

    vector<vector<int> > graph2 = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == 0);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "-1");
}
TEST_CASE("Test isConnected")
{
    ariel::Graph g(false);
    vector<vector<int> > graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == 1);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int> > graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == 0);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g(false);
    vector<vector<int> > graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int> > graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g(false);
    vector<vector<int> > graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    vector<vector<int> > graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g(false);
    vector<vector<int> > graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int> > graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int> > graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g(false);
    vector<vector<int> > graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
/***************** Testing Directed graphs ********************/

TEST_CASE("Testing directed unweighted graphs")
{

    ariel::Graph g(true);
    vector<vector<int> > graph4 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 0) == "2->1->0");
}
TEST_CASE("Testing undirected negative cycle graphs")
{
    ariel::Graph g(true);
    vector<vector<int>> graph5{
        {0, 6, 7, 0, 0},
        {6, 0, 8, -4, 0},
        {7, 8, 0, 0, 5},
        {0, -4, 0, 0, 7},
        {0, 0, 5, 7, 0}};
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
    CHECK(ariel::Algorithms::negativeCycle(g) == true);//"Negative cycle detected: 3->1->3"

    vector<vector<int>> graph6 = {
        {0, -1, 0, -1, 0},
        {-1, 0, -1, 0, 0},
        {0, -1, 0, 0, -1},
        {-1, 0, 0, 0, -1},
        {0, 0, -1, -1, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
    CHECK(ariel::Algorithms::negativeCycle(g) == true);//"Negative cycle detected: 4->2->4"
}