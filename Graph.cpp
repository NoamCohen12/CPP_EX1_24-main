#include <string>
#include "Graph.hpp"

using namespace ariel;

Graph::Graph(vector<vector<int> > matrix1, size_t v1, bool isDirected1)
{
    this->matrix = matrix1;
    this->v = v1;
    this->isDirected = isDirected1;
}

size_t Graph::getSize()
{
    return this->v;
}

void Graph::loadGraph(vector<vector<int> > graph, bool isdirected)
{
    if (graph.size() != graph[0].size() || graph.size() ==0)
    {
        std::cout << "your matrix should be squer" << endl;
        return;
    }

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        if (matrix[i][i] != 0)
        {
           std::cout << "your matrix should have ZERO in diagonal" << endl;
           return;
        }
    }
   

    // Clear the existing matrix and resize to match the input graph size
    this->isDirected = isdirected;
    matrix.clear();
    this->v = graph.size();
    matrix.resize(v, vector<int>(v, 0));
    for (size_t i = 0; i < graph.size(); i++)
    {
        for (size_t j = 0; j < graph.size(); j++)
        {
            matrix[i][j] = graph[i][j];
        }
    }
}

void Graph::printGraph()
{
    for (size_t i = 0; i < v; i++)
    {
        for (size_t j = 0; j < v; j++)
        {
            cout << matrix[i][j] << " "; // Print matrix element followed by a space
        }
        cout << endl; // Move to the next line after printing a row
    }
}
