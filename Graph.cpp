#include "Graph.hpp"

using namespace ariel;

Graph::Graph(bool isDirected1)
{
    this->num_vertices = 0;
    this->isDirected = isDirected1;
    this->type_graph = 0;
}

size_t Graph::getSize()const
{
    return this->num_vertices;
}


void Graph::loadGraph(vector<vector<int> > &graph)
{
    this->num_vertices = graph.size();
    this->matrix = graph;
    if (graph.size() != graph[0].size() || graph.empty())
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
    this->num_vertices = graph.size();
    this->type_graph = graph_type(graph);
    matrix.resize(num_vertices, vector<int>(num_vertices, 0));
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
  int num_edges = 0;
    int vertices = this->num_vertices;
    for (size_t i = 0; i < vertices; i++)
    {
        // only count the upper triangle of the matrix
        for (size_t j = 0; j < vertices; j++)
        {
            if (this->matrix[i][j] != 0)
            {
                num_edges++;
            }
        }
    }
    if (this->isDirected)
    {
        cout << "The graph is directed. V(G) = " << vertices << ", E(G) = " << num_edges << endl;
    }
    else
    {
        cout << "The graph is undirected. V(G) = " << vertices << " E(G) = " << (num_edges / 2) << endl;
    }
}

vector<vector<int> > Graph::get_matrix() const
{
    return this->matrix;
}

bool Graph::isDirectedG() const
{
    return this->isDirected;
}

int Graph::get_type_graph() const
{
    return this->type_graph;
}



Graph Graph::getTranspose() const {
    Graph gTranspose(true);
    size_t num_vertices = this->num_vertices;
    vector<vector<int>> transpose(num_vertices, vector<int>(num_vertices, 0));
    for (size_t i = 0; i < num_vertices; ++i) {
        for (size_t j = 0; j < num_vertices; ++j) {
            transpose[j][i] = this->matrix[i][j];
        }
    }
    gTranspose.loadGraph(transpose); // Assign the transposed matrix to GT
    return gTranspose;
}

Graph Graph::add_opposite_edges() const {
    Graph fix_graph(true);
    size_t num_vertices = this->num_vertices;
    vector<vector<int>> new_matrix(num_vertices, vector<int>(num_vertices, 0));
    for (size_t i = 0; i < num_vertices; ++i) {
        for (size_t j = 0; j < num_vertices; ++j) {
            new_matrix[j][i] = this->matrix[j][i];
            if (new_matrix[j][i] > 0 && new_matrix[i][j] == 0)
            {
               new_matrix[i][j] = this->matrix[j][i];
            }
        }
    }
    fix_graph.loadGraph(new_matrix); // Assign the new_matrix to fix_graph
    return fix_graph;
}







int Graph::graph_type(vector<vector<int> > &graph)
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
             if (matrix[i][j] > 0)
            {
                type = positive_edges;
            }
        }
    }
    return type;
}
