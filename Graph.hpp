#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
#define without_weights_edges 0
#define positive_edges 1
#define negative_edges 2
using namespace std;
namespace ariel
{
    class Graph

    {
    private:
        vector<vector<int> > matrix; // adjacency list
        size_t num_vertices;         // number of vertixs
        bool isDirected;
        int type_graph;

    public:
        // main function
        Graph(bool isDirected);
        void loadGraph(vector<vector<int> > &graph);
        void printGraph() const;
        // help function
        int graph_type(vector<vector<int> > &graph);

        // gets
        size_t getSize() const;
        vector<vector<int> > get_matrix() const;
        bool isDirectedG() const;
        int get_type_graph() const;

        // creation functions
        Graph getTranspose() const;
        Graph add_opposite_edges() const;
    };
}
#endif