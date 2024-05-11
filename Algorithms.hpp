#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>

#include "Graph.hpp"

using namespace std;

namespace ariel
{

    class Algorithms
    {
    public:
        static vector<vector<int> > dfs_graph(Graph g);

        static vector<vector<int> > dfs_Vertex(Graph &g, int root);

        static int bfs(vector<vector<int> > adj, int start);

        static string find_path_bfs(Graph &g, size_t start, size_t end);

        static int dijkstra(Graph &matrix, size_t source, size_t target);

        static int bellmanFord(Graph &g, size_t source, size_t target);

        static bool dfs_D_cycle_detection(size_t vertex, int parent, const vector<vector<int> > &graph, vector<bool> &visited, vector<int> &cycle);

        static bool is_cycle_D(const vector<vector<int> > &graph);

        static bool dfs_UD_cycle_detection(Graph &g, size_t v, vector<bool> &visited, vector<bool> &in_recursion_stack, vector<int> &path);

        static bool is_cycle_UD(Graph &g);

        static void print_cycle(vector<int> &cycle);

        static int isConnected(Graph g);

        static string shortestPath(Graph g, size_t start, size_t end);

        static bool isContainsCycle(Graph &g);

        static int isBipartite(Graph g);

        static int negativeCycle(Graph g);
    };
}
#endif