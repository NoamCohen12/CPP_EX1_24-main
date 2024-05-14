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
        size_t num_vertices;                    // number of vertixs
        bool isDirected;
        int type_graph;              

    public:
        Graph( bool isDirected);
        void loadGraph(vector<vector<int> > &graph);
        void printGraph();
        size_t getSize()const; 
        vector<vector<int> > get_matrix()const;
        bool isDirectedG()const;
        int graph_type(vector<vector<int> > &graph);
        int get_type_graph()const;
        Graph getTranspose() const;
        Graph getClique() const;
    };
}
#endif