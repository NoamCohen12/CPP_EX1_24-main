#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include <vector>
#include <string>
using namespace std;
namespace ariel{
class Graph

{
private:
    vector<vector<int>> matrix; // adjacency list
    size_t v;                    // number of vertixs
    bool isDirected;

public:
    Graph( vector<vector<int>> matrix, size_t v, bool isDirected);
    void loadGraph(vector<vector<int>> graph,bool isdirected);
    void printGraph();
    size_t getSize();

};
}
#endif