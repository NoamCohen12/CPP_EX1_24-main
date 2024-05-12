#include "Graph.hpp"

using namespace ariel;

Graph::Graph(bool isDirected1)
{
    this->v = 0;
    this->isDirected = isDirected1;
    this->type_graph = 0;
}

size_t Graph::getSize()
{
    return this->v;
}


void Graph::loadGraph(vector<vector<int> > &graph)
{
    this->v = graph.size();
    this->matrix = graph;
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



Graph Graph::getTranspose() const {
    Graph gTranspose(true);
    size_t n = this->v;
    vector<vector<int>> transpose(n, vector<int>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            transpose[j][i] = this->matrix[i][j];
        }
    }
    gTranspose.loadGraph(transpose); // Assign the transposed matrix to GT
    return gTranspose;
}

Graph Graph::getClique() const {
    Graph gClique(true);
    size_t n = this->v;
    vector<vector<int>> Clique(n, vector<int>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            Clique[j][i] = this->matrix[j][i];
            if (Clique[j][i] > 0 && Clique[i][j] == 0)
            {
               Clique[i][j] = this->matrix[j][i];
            }
        }
    }
    gClique.loadGraph(Clique); // Assign the Clique matrix to gClique
    return gClique;
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
