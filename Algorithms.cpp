#include "Algorithms.hpp"
using namespace ariel;
vector<vector<int> > Algorithms::dfs_graph(Graph g)
{
    size_t num_nodes = g.get_matrix().size();
    vector<bool> visited(num_nodes, false);

    vector<vector<int> > trees;
    vector<vector<int> > matrix = g.get_matrix();

    for (size_t i = 0; i < num_nodes; i++)
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

                for (int neighbor : matrix[(size_t)current_node])
                {
                    if (neighbor != 0 && !visited[(size_t)neighbor])
                    {
                        s.push(neighbor);
                        visited[(size_t)neighbor] = true;
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
    size_t num_nodes = g.get_matrix().size();
    vector<bool> visited(num_nodes, false);
    vector<vector<int> > trees(num_nodes);
    vector<vector<int> > matrix = g.get_matrix();

    stack<int> s;
    s.push(root);
    visited[(size_t)root] = true;

    while (!s.empty())
    {
        int current_node = s.top();
        s.pop();

        for (int neighbor : matrix[(size_t)current_node])
        {
            if (neighbor != 0 && !visited[(size_t)neighbor])
            {
                s.push(neighbor);
                visited[(size_t)neighbor] = true;
                trees[(size_t)current_node].push_back(neighbor);
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
    visited[(size_t)start_node] = true;

    while (!queue.empty())
    {
        int current_node = queue.front();
        queue.pop();

        for (int i = 0; i < adjacency_matrix[(size_t)current_node].size(); i++)
        {
            if (adjacency_matrix[(size_t)current_node][(size_t)i] > 0 && !visited[(size_t)i])
            {
                queue.push(i);
                visited[(size_t)i] = true;
            }
        }
    }
    for (size_t i = 0; i < visited.size(); i++)
    {
        if (visited[(size_t)i] == false)
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
string ariel::Algorithms::find_path_bfs(Graph &g, size_t start, size_t end)
{
    vector<vector<int>> matrix = g.get_matrix();
    unordered_map<int, int> parent_map;
    queue<int> q;
    q.push(start);
    parent_map[start] = -1; // -1 indicates no parent

    // Perform BFS to find the path
    while (!q.empty())
    {
        size_t current = (size_t)q.front();
        q.pop();

        if (current == end)
        {
            // Reconstruct the path
            vector<int> path;
            int node = end;
            while (node != -1)
            {
                path.push_back(node);
                node = parent_map[node];
            }
            // Construct the path string
            stringstream ss;
            for (int i = path.size() - 1; i >= 0; --i)
            {
                ss << path[(size_t)i];
                if (i > 0)
                    ss << "->";
            }
            return ss.str();
        }

        // Iterate through neighbors of current node
        for (size_t neighbor = 0; neighbor < matrix[current].size(); ++neighbor)
        {
            if (matrix[current][neighbor] != 0 && parent_map.find(neighbor) == parent_map.end())
            {
                q.push(neighbor);
                parent_map[neighbor] = current;
            }
        }
    }
    return "-1"; // No path found
}


int Algorithms::dijkstra(Graph &g, size_t source, size_t target)
{
     size_t n = g.get_matrix().size();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        size_t u =(size_t)pq.top().second;
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        if (u == target)
            break;

        for (size_t v = 0; v < n; ++v)
        {
            if (g.get_matrix()[u][v] != 0 && !visited[v] && dist[u] + g.get_matrix()[u][v] < dist[v])
            {
                dist[v] = dist[u] + g.get_matrix()[u][v];
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest path
    vector<int> path;
    int current = target;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[(size_t)current];
    }

    cout << "Shortest path from source to target:" << endl;
    for (size_t i = path.size() - 1; i >= 0; --i)
    {
        cout << path[i];
        if (i > 0)
            cout << "->";
    }
    // If no path found, return -1
    if (parent[target] == -1)
    {
        return -1;
    }

    // Return the length of the shortest path
    return dist[target];
}

int Algorithms::bellmanFord(Graph &g, size_t source, size_t target)
{
    size_t n = g.get_matrix().size();
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    dist[source] = 0;

    // Relax all edges |V| - 1 times
    for (size_t i = 0; i < n - 1; ++i)
    {
        for (size_t u = 0; u < n; ++u)
        {
            for (size_t v = 0; v < n; ++v)
            {
                if (g.get_matrix()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.get_matrix()[u][v] < dist[v])
                {
                    dist[v] = dist[u] + g.get_matrix()[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative cycles
    for (size_t u = 0; u < n; ++u)
    {
        for (size_t v = 0; v < n; ++v)
        {
            if (g.get_matrix()[u][v] != 0 && dist[u] != INT_MAX && dist[u] + g.get_matrix()[u][v] < dist[v])
            {
                cout << "Graph contains negative weight cycle" << endl;
                return -1;
            }
        }
    }

    // Print the shortest path
    vector<int> path;
    int current = target;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[(size_t)current];
    }

    cout << "Shortest path from source to target:" << endl;
    for (size_t i = path.size() - 1; i >= 0; --i)
    {
        cout << path[i];
        if (i > 0)
            cout << "->";
    }

    // If no path found, return -1
    if (parent[target] == -1)
    {
        return -1;
    }

    // Return the length of the shortest path
    return dist[target];
}

bool Algorithms::dfs_D_cycle_detection(size_t vertex, int parent, const vector<vector<int>>& graph, vector<bool>& visited, vector<int>& current_cycle)
{
    visited[vertex] = true;
    for (size_t neighbor = 0; neighbor < graph.size(); ++neighbor) {
        if (graph[vertex][neighbor] > 0) { // Check if there is an edge between the vertices
            if (!visited[neighbor]) {
                current_cycle.push_back(vertex); // Add current vertex to cycle
                if (dfs_D_cycle_detection(neighbor, vertex, graph, visited, current_cycle)) {
                    return true;
                }
                current_cycle.pop_back(); // Remove current vertex if no cycle found in subtree
            } 
            else if (neighbor != parent) {
                current_cycle.push_back(vertex); // Add current vertex to cycle
                current_cycle.push_back(neighbor); // Add neighbor to cycle
                return true; // Cycle detected
            }
        }
    }
    return false; // No cycle found
}
bool Algorithms::is_cycle_D(const vector<vector<int> > &graph)
{
     size_t n = graph.size();
    vector<bool> visited(n, false);

    for (size_t v = 0; v < n; ++v) {
        if (!visited[v]) {
            vector<int> current_cycle;
            if (dfs_D_cycle_detection(v, -1, graph, visited, current_cycle)) {
                cout << "Cycle found: ";
               print_cycle(current_cycle);
                //cout << current_cycle[0]; // Print the first vertex again to close the cycle
                //cout << endl;
                return true; // Cycle detected
            }
        }
    }
   // cout << "No cycle found" << endl;

    return false; // No cycle found
}
void Algorithms::print_cycle(vector<int>& cycle) {
    //cout << "Cycle found: ";
    for (size_t i = 0; i < cycle.size() ; ++i) {
        cout << cycle[i];
        if (i < cycle.size() - 1) {
            cout << "->";
        }
    }
    cout << endl;
}

string Algorithms::shortestPath(Graph g, size_t start, size_t end)
{
    if (start >= g.get_matrix().size() || start < 0 || end >= g.get_matrix().size() || end < 0)
    {
        throw invalid_argument("Invalid source or destination vertex");
    }
    if (start == end)
    {
       return to_string(start);
         
    }
    if (g.get_type_graph() == without_weights_edges)
    {

       return find_path_bfs(g, start, end);
        
    }
    else if (g.get_type_graph() == positive_edges)
    {
        dijkstra(g, start, end);
        return "0";
    }
    else if (g.get_type_graph() == negative_edges)
    {
        bellmanFord(g, start, end);
        return "0";
    }

    return "-1";
}

bool Algorithms::dfs_UD_cycle_detection(Graph& g, size_t v, vector<bool>& visited, vector<bool>& in_recursion_stack, vector<int>& path) {
    visited[v] = true;
    in_recursion_stack[v] = true;
    path.push_back(v);

    for (size_t neighbor = 0; neighbor < g.get_matrix()[v].size(); ++neighbor) {
        if (g.get_matrix()[v][neighbor] != 0) { // Check if there's an edge
            if (!visited[neighbor]) {
                if (dfs_UD_cycle_detection(g, neighbor, visited, in_recursion_stack, path)) {
                    return true;
                }
            } else if (in_recursion_stack[neighbor]) {
                return true; // Cycle detected
            }
        }
    }
    in_recursion_stack[v] = false; // Remove from recursion stack when backtracking
    path.pop_back(); // Remove from the current path
    return false;
}

bool Algorithms::is_cycle_UD(Graph& g) {
    size_t n = g.get_matrix().size();
    vector<bool> visited(n, false);
    vector<bool> in_recursion_stack(n, false);
    vector<int> path;

    for (size_t i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs_UD_cycle_detection(g, i, visited, in_recursion_stack, path)) {
                print_cycle(path);
                return true;
            }
        }
    }
    // No cycle found
    cout << "-1" << endl;
    return false;
}





bool Algorithms::isContainsCycle(Graph &g)
{
    if (g.isDirectedG())
    {

    return(is_cycle_UD(g));
    }
    else if (!g.isDirectedG())
    {
      return(is_cycle_D(g.get_matrix()));
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
