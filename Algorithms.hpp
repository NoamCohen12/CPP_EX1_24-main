#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

namespace ariel
{

    class Algorithms
    {
    public:
        static void vector<vector<int>>dfs(Graph g)

        static void bfs(vector<vector<int> > &adj, int start);

        static int isConnected(Graph g);

        static int shortestPath(Graph g, int start, int end);

        static int isContainsCycle(Graph g);

        static int isBipartite(Graph g);

        static int negativeCycle(Graph g);
    };
}
#endif