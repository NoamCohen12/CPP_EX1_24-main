#include "Graph.hpp"

using namespace ariel;

Graph::Graph(vector<vector<int> > matrix1, size_t v1, bool isDirected1)
{
    this->matrix = matrix1;
    this->v = v1;
    this->isDirected = isDirected1;
    this->type_graph = 0;
}

size_t Graph::getSize()
{
    return this->v;
}

void Graph::loadGraph(vector<vector<int> > graph)
{
    if (graph.size() != graph[0].size() || graph.size() == 0)
    {

        throw invalid_argument("your matrix should be squer");
    }

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        if (matrix[i][i] != 0)
        {
            throw invalid_argument("your matrix should have ZERO in diagonal");
        }
    }

    // Clear the existing matrix and resize to match the input graph size
    matrix.clear();
    this->v = graph.size();
    this->type_graph = graph_type(graph);
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

vector<vector<int> > Graph::get_matrix()
{
    return this->matrix;
}

bool Graph::isDirectedG()
{
    return this->isDirected;
}

int Graph::get_type_graph()
{
    return this->type_graph;
}

int Graph::graph_type(vector<vector<int> > graph)
{
    int type = without_weights_edges;
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] < 0)
            {
                return negative_edges;
            }
            else if (matrix[i][j] > 0)
            {
                type = positive_edges;
            }
        }
    }
    return type;
}
