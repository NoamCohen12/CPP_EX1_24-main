#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm> 
#include <climits>


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

        static int find_path_bfs(Graph& g, int start, int end);

        static int dijkstra(Graph& matrix, int source, int target);
         static int bellmanFord(Graph& g, int source, int target);


        static int isConnected(Graph g);

        static int shortestPath(Graph g, int start, int end);

        static int isContainsCycle(Graph g);

        static int isBipartite(Graph g);

        static int negativeCycle(Graph g);
    };
}
#endif