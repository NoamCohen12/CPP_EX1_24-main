#include <Algorithms.hpp>
#include <queue>
using namespace ariel;
vector<vector<int>> Algorithms::dfs(Graph g) {
  int num_nodes = g.matrix.size();
  vector<bool> visited(num_nodes, false);
  vector<vector<int>> components;

  for (int i = 0; i < num_nodes; i++) {
    if (!visited[i]) {
      stack<int> s;
      vector<int> current_component;
      s.push(i);
      visited[i] = true;

      while (!s.empty()) {
        int current_node = s.top();
        s.pop();
        current_component.push_back(current_node);

        for (int neighbor : g.matrix[current_node]) {
          if (!visited[neighbor]) {
            s.push(neighbor);
            visited[neighbor] = true;
          }
        }
      }
      components.push_back(current_component);
    }
  }

  return components;
}


















int Algorithms::bfs(vector<vector<int> > adjacency_matrix, int start_node)
{
    vector<bool> visited(adjacency_matrix.size(), false);
    queue<int> queue;

    queue.push(start_node);
    visited[start_node] = true;

    while (!queue.empty())
    {
        int current_node = queue.front();
        queue.pop();

        for (int i = 0; i < adjacency_matrix[current_node].size(); i++)
        {
            if (adjacency_matrix[current_node][i] > 0 && !visited[i])
            {
                queue.push(i);
                visited[i] = true;
            }
        }
    }
    for (size_t i = 0; i < visted.size; i++)
    {
        if (visted[i] == false)
        {
            return 0;
        }
    }
    return 1;
}

// in the case that graph is undirected we use BFS algoritem
//  check if we visted all the vertix 


// in the case that graph is undirected we use DFS algoritem 
//we got many trees and we make DFS For the second time on the src of last tree 
//if we got one tree the graph isConcted




static int Algorithms::isConnected(Graph g)
{
    if (g.isDirected == false)
    {
        return bfs((&g.matrix), 0)
    }






}

static int Algorithms::shortestPath(Graph g, int start, int end)
{
}

static int Algorithms::isContainsCycle(Graph g)
{
}

static int Algorithms::isBipartite(Graph g)
{
}

static negativeCycle(Graph g)
{
}
