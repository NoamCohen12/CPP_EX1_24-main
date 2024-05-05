#include "Algorithms.hpp"
using namespace ariel;
vector<vector<int> > Algorithms::dfs_graph(Graph g)
{
    int num_nodes = g.get_matrix().size();
    vector<bool> visited(num_nodes, false);
    vector<vector<int> > trees;
    vector<vector<int> > matrix = g.get_matrix();

    for (int i = 0; i < num_nodes; i++)
    {
        if (!visited[i])
        {
            stack<int> s;
            vector<int> current_component;
            s.push(i);
            visited[i] = true;

            while (!s.empty())
            {
                int current_node = s.top();
                s.pop();
                current_component.push_back(current_node);

                for (int neighbor : matrix[current_node])
                {
                    if (neighbor != 0 && !visited[neighbor])
                    {
                        s.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            trees.push_back(current_component);
        }
    }

    return trees;
}

vector<vector<int> > Algorithms::dfs_Vertex(Graph &g, int root)
{
    int num_nodes = g.get_matrix().size();
    vector<bool> visited(num_nodes, false);
    vector<vector<int> > trees(num_nodes);
    vector<vector<int> > matrix = g.get_matrix();

    stack<int> s;
    s.push(root);
    visited[root] = true;

    while (!s.empty())
    {
        int current_node = s.top();
        s.pop();

        for (int neighbor : matrix[current_node])
        {
            if (neighbor != 0 && !visited[neighbor])
            {
                s.push(neighbor);
                visited[neighbor] = true;
                trees[current_node].push_back(neighbor);
            }
        }
    }

    return trees;
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
    for (size_t i = 0; i < visited.size(); i++)
    {
        if (visited[i] == false)
        {
            return 0;
        }
    }
    return 1;
}

// in the case that graph is undirected we use BFS algoritem
//  check if we visted all the vertix

// in the case that graph is undirected we use DFS algoritem
// we got many trees and we make DFS For the second time on the root of last tree
// if we got one tree the graph isConcted

int Algorithms::isConnected(Graph g)
{
    if (!g.isDirectedG())
    {
        return bfs((g.get_matrix()), 0);
    }

    vector<vector<int> > trees_from_dfs = dfs_graph(g);
    int last_root = trees_from_dfs.back().front();
    vector<vector<int> > trees_from_secend_dfs = dfs_Vertex(g, last_root);
    return (trees_from_secend_dfs.size() == 1);
}

// Function to find a path between start and end vertices using BFS and print the path
    int Algorithms::find_path_bfs(Graph& g, int start, int end) {
    vector<vector<int>> matrix = g.get_matrix();
    unordered_map<int, int> parent_map;
    queue<int> q;
    q.push(start);
    parent_map[start] = -1; // -1 indicates no parent

    // Perform BFS to find the path
    while (!q.empty()) {
        int current = q.front();
       // cout << "current:" << current << endl;
        q.pop();

        if (current == end) {
           // cout << "current == end" << endl;
            // Reconstruct and print the path
            vector<int> path;
            int node = end;
            while (node != -1) {
                path.push_back(node);
                node = parent_map[node];
            }
            reverse(path.begin(), path.end());
            for (size_t i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i != path.size() - 1) {
                    cout << "->";
                }
            }
            cout << endl;
            return 0;
        }

        // Iterate through neighbors of current node
        for (size_t neighbor = 0; neighbor < matrix[current].size(); ++neighbor) {
            if (matrix[current][neighbor] != 0 && parent_map.find(neighbor) == parent_map.end()) {
                // If there is an edge from current to neighbor and neighbor is not visited
                //cout << neighbor << " neighbor of:" << current << endl;
                q.push(neighbor);
                parent_map[neighbor] = current;
            }
        }
    }
    return -1; // Path not found
}

int Algorithms::dijkstra(Graph& g, int source, int target) {
    int n = g.get_matrix().size();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        if (u == target) break;

        for (int v = 0; v < n; ++v) {
            if (g.get_matrix()[u][v] != 0 && !visited[v] && dist[u] + g.get_matrix()[u][v] < dist[v]) {
                dist[v] = dist[u] + g.get_matrix()[u][v];
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest path
    vector<int> path;
    int current = target;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    cout << "Shortest path from source to target:" << endl;
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i > 0) cout << " -> ";
    }
    // If no path found, return -1
    if (parent[target] == -1) {
        return -1;
    }

    // Return the length of the shortest path
    return dist[target];
}

     int Algorithms:: bellmanFord(Graph& g, int source, int target) {
        int n = g.get_matrix().size();
        vector<int> dist(n, INT_MAX);
        vector<int> parent(n, -1);

        dist[source] = 0;

        // Relax all edges |V| - 1 times
        for (int i = 0; i < n - 1; ++i) {
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    if (g.get_matrix()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.get_matrix()[u][v] < dist[v]) {
                        dist[v] = dist[u] + g.get_matrix()[u][v];
                        parent[v] = u;
                    }
                }
            }
        }

        // Check for negative cycles
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (g.get_matrix()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.get_matrix()[u][v] < dist[v]) {
                    cout << "Graph contains negative weight cycle" << endl;
                    return -1;
                }
            }
        }

       // Print the shortest path
    vector<int> path;
    int current = target;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    cout << "Shortest path from source to target:" << endl;
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i > 0) cout << " -> ";
    }

        // If no path found, return -1
        if (parent[target] == -1) {
            return -1;
        }

        // Return the length of the shortest path
        return dist[target];
    }











int Algorithms::shortestPath(Graph g, int start, int end)
{
    if (start >= g.get_matrix().size() || start < 0 || end >= g.get_matrix().size() || end < 0)
    {
        throw invalid_argument("Invalid source or destination vertex");
    }
    if (start == end)
    {
        to_string(start);
        return 0;
    }
    if (g.get_type_graph() == without_weights_edges)
    {
        
        find_path_bfs(g,start,end);
        return 0;
    }
    else if (g.get_type_graph() == positive_edges)
    {
        dijkstra(g,start,end);
        return 0;
    }
    else if (g.get_type_graph() == negative_edges)
    {
        bellmanFord(g,start,end);
        return 0;
    }

    return -1;
}

int Algorithms::isContainsCycle(Graph g)
{
    if (g.isDirected)
    {
        /* code */
    }
    else if (!g.isDirected)
    {
        /* code */
    }
    
    
    return 1;
}

int Algorithms::isBipartite(Graph g)
{
    return 1;
}

void negativeCycle(Graph g)
{
    
}
