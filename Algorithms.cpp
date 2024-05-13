#include "Algorithms.hpp"
using namespace ariel;
vector<bool> Algorithms::dfs_graph(Graph &graph)
{
    size_t number_vertixs = graph.getSize(); // number of vertix
    vector<bool> visited(number_vertixs, false);
    vector<vector<int> > matrix = graph.get_matrix();
    stack<size_t> Stack;
    for (size_t i = 0; i < number_vertixs; i++)
    {
        if (!visited[i])
        {
            Stack.push(i);
            visited[i] = true;

            while (!Stack.empty())
            {
                size_t current_node = Stack.top();
                Stack.pop();

                for (size_t neighbor = 0; neighbor < graph.get_matrix()[(size_t)current_node].size(); neighbor++)
                {
                    if (graph.get_matrix()[current_node][neighbor] != 0 && !visited[neighbor])
                    {
                        Stack.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }
    }
    return visited;
}

bool Algorithms::bfs(vector<vector<int> > adjacency_matrix, int start_node)
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
            if (adjacency_matrix[(size_t)current_node][(size_t)i] != 0 && !visited[(size_t)i])
            {
                queue.push(i);
                visited[(size_t)i] = true;
            }
        }
    }
    for (size_t i = 0; i < visited.size(); i++)
    {
        if (!visited[(size_t)i])
        {
            return false;
        }
    }
    return true;
}

// in the case that graph is undirected we use BFS algoritem
//  check if we visted all the vertix

// in the case that graph is undirected we use DFS algoritem
// we got many trees and we make DFS For the second time on the root of last tree
// if we got one tree the graph isConnected

bool Algorithms::isConnected(Graph graph)
{
    if (!graph.isDirectedG())
    {
        return bfs((graph.get_matrix()), 0);
    }
    size_t number_vertixs = graph.getSize();
    vector<bool> visit_dfs1 = dfs_graph(graph);
    Graph GTranspose = graph.getTranspose();
    vector<bool> visit_dfs2 = dfs_graph(GTranspose);
    for (size_t i = 0; i < number_vertixs; i++)
    {
        if (!visit_dfs1[i] || !visit_dfs2[i])
        {
            return false;
        }
    }

    return true;
}

// Function to find a path between start and end vertices using BFS and print the path
string ariel::Algorithms::find_path_bfs(Graph &graph, size_t start, size_t end)
{
    vector<vector<int> > matrix = graph.get_matrix();
    unordered_map<size_t, int> parent_map;
    queue<size_t> Queue;
    Queue.push(start);
    parent_map[start] = -1; // -1 indicates no parent

    // Perform BFS to find the path
    while (!Queue.empty())
    {
        size_t current = (size_t)Queue.front();
        Queue.pop();

        if (current == end)
        {
            // Reconstruct the path
            vector<int> path;
            int node = (int)end;
            while (node != -1)
            {
                path.push_back(node);
                node = parent_map[(size_t)node];
            }
            // Construct the path string
            stringstream ans;
            for (int i = (int)path.size() - 1; i >= 0; --i)
            {
                ans << path[(size_t)i];
                if (i > 0)
                {
                    ans << "->";
                }
            }
            return ans.str();
        }

        // Iterate through neighbors of current node
        for (size_t neighbor = 0; neighbor < matrix[current].size(); ++neighbor)
        {
            if (matrix[current][neighbor] != 0 && parent_map.find(neighbor) == parent_map.end())
            {
                Queue.push(neighbor);
                parent_map[neighbor] = (int)current;
            }
        }
    }
    return "-1"; // No path found
}

string Algorithms::dijkstra(const Graph &graph, size_t source, size_t target)
{
    size_t number_vertixs = graph.get_matrix().size();
    vector<int> dist(number_vertixs, INT_MAX);
    vector<int> parent(number_vertixs, -1);
    vector<bool> visited(number_vertixs, false);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Pqueue;

    dist[source] = 0;
    Pqueue.push({0, source});

    while (!Pqueue.empty())
    {
        size_t vertex = (size_t)Pqueue.top().second;
        Pqueue.pop();

        if (visited[vertex])
        {
            continue;
        }
        visited[vertex] = true;

        if (vertex == target)
        {
            break;
        }

        for (size_t k = 0; k < number_vertixs; ++k)
        {
            if (graph.get_matrix()[vertex][k] != 0 && !visited[k] && dist[vertex] + graph.get_matrix()[vertex][k] < dist[k])
            {
                dist[k] = dist[vertex] + graph.get_matrix()[vertex][k];
                parent[k] = (int)vertex;
                Pqueue.push({dist[k], k});
            }
        }
    }

    // Reconstruct the shortest path
    vector<int> path;
    int current = (int)target;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[(size_t)current];
    }

    if (parent[target] == -1)
    {
        return "-1"; // No path found
    }

    // Convert the path to string
    string shortest_path;
    for (size_t i = path.size() - 1; i >= 0; --i)
    {
        shortest_path += to_string(path[i]);
        if (i > 0)
        {
            shortest_path += "->";
        }
    }

    return shortest_path;
}
string Algorithms::bellmanFord(const Graph &graph, size_t source, size_t target)
{
    size_t number_vertixs = graph.get_matrix().size();
    vector<int> dist(number_vertixs, INT_MAX);
    vector<int> parent(number_vertixs, -1);

    dist[source] = 0;

    // Relax all edges |V| - 1 times
    for (size_t i = 0; i < number_vertixs - 1; ++i)
    {
        for (size_t j = 0; j < number_vertixs; ++j)
        {
            for (size_t k = 0; k < number_vertixs; ++k)
            {
                if (graph.get_matrix()[j][k] != 0 && dist[j] != INT_MAX && dist[j] + graph.get_matrix()[j][k] < dist[k])
                {
                    dist[k] = dist[j] + graph.get_matrix()[j][k];
                    parent[k] = (int)j;
                }
            }
        }
    }

    // Check for negative cycles
    for (size_t j = 0; j < number_vertixs; ++j)
    {
        for (size_t k = 0; k < number_vertixs; ++k)
        {
            if (graph.get_matrix()[j][k] != 0 && dist[j] != INT_MAX && dist[j] + graph.get_matrix()[j][k] < dist[k])
            {
                // Negative cycle detected
                cout << "Graph contains negative weight cycle" << endl;
                return "-1";
            }
        }
    }

    // Reconstruct the shortest path
    vector<int> path;
    int current = (int)target;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[(size_t)current];
    }

    if (parent[target] == -1)
    {
        return "-1"; // No path found
    }

    // Convert the path to string
    string shortest_path;
    for (size_t i = path.size() - 1; i >= 0; --i)
    {
        shortest_path += to_string(path[i]);
        if (i > 0)
        {
            shortest_path += "->";
        }
    }

    return shortest_path;
}

bool Algorithms::dfs_D_cycle_detection(size_t vertex, const vector<vector<int> > &graph, vector<bool> &visited, int parent, vector<size_t> &current_cycle)

// bool Algorithms::dfs_D_cycle_detection(size_t vertex, int parent, const vector<vector<int> > &graph, vector<bool> &visited, vector<size_t> &current_cycle)
{
    visited[vertex] = true;
    for (size_t neighbor = 0; neighbor < graph.size(); ++neighbor)
    {
        if (graph[vertex][neighbor] != 0)
        { // Check if there is an edge between the vertices
            if (!visited[neighbor])
            {
                current_cycle.push_back(vertex); // Add current vertex to cycle
                if (dfs_D_cycle_detection(neighbor, graph, visited, (int)vertex, current_cycle))
                {
                    return true;
                }
                current_cycle.pop_back(); // Remove current vertex if no cycle found in subtree
            }
            else if (neighbor != parent)
            {
                current_cycle.push_back(vertex);   // Add current vertex to cycle
                current_cycle.push_back(neighbor); // Add neighbor to cycle
                return true;                       // Cycle detected
            }
        }
    }
    return false; // No cycle found
}
bool Algorithms::is_cycle_D(const vector<vector<int> > &graph)
{
    size_t number_vertixs = graph.size();
    vector<bool> visited(number_vertixs, false);

    for (size_t k = 0; k < number_vertixs; ++k)
    {
        if (!visited[k])
        {
            vector<size_t> current_cycle;
            if (dfs_D_cycle_detection(k, graph, visited, -1, current_cycle))
            {
                cout << "Cycle found: ";
                print_cycle(current_cycle);
                // cout << current_cycle[0]; // Print the first vertex again to close the cycle
                // cout << endl;
                return true; // Cycle detected
            }
        }
    }
    // cout << "No cycle found" << endl;

    return false; // No cycle found
}
void Algorithms::print_cycle(vector<size_t> &cycle)
{
    // cout << "Cycle found: ";
    for (size_t i = 0; i < cycle.size(); ++i)
    {
        cout << cycle[i];
        if (i < cycle.size() - 1)
        {
            cout << "->";
        }
    }
    cout << endl;
}

string Algorithms::shortestPath(Graph graph, size_t start, size_t end)
{
    if (start >= graph.get_matrix().size() || start < 0 || end >= graph.get_matrix().size() || end < 0)
    {
        throw invalid_argument("Invalid source or destination vertex");
    }

    if (negativeCycle(graph))
    {
        return "-1"; // if there is negative cycle there is not shortest path
    }

    if (start == end)
    {
        return to_string(start);
    }
    if (graph.get_type_graph() == without_weights_edges)
    {

        return find_path_bfs(graph, start, end);
    }
    if (graph.get_type_graph() == positive_edges)
    {
        return dijkstra(graph, start, end);
    }
    if (graph.get_type_graph() == negative_edges)
    {
        return bellmanFord(graph, start, end);
    }

    return "-1";
}

bool Algorithms::dfs_UD_cycle_detection(Graph &graph, size_t source, vector<bool> &visited, vector<bool> &in_recursion_stack, vector<size_t> &path)
{
    visited[source] = true;
    in_recursion_stack[source] = true;
    path.push_back(source);

    for (size_t neighbor = 0; neighbor < graph.get_matrix()[source].size(); ++neighbor)
    {
        if (graph.get_matrix()[source][neighbor] != 0)
        { // Check if there's an edge
            if (!visited[neighbor])
            {
                if (dfs_UD_cycle_detection(graph, neighbor, visited, in_recursion_stack, path))
                {
                    return true;
                }
            }
            else if (in_recursion_stack[neighbor])
            {
                return true; // Cycle detected
            }
        }
    }
    in_recursion_stack[source] = false; // Remove from recursion stack when backtracking
    path.pop_back();                    // Remove from the current path
    return false;
}

bool Algorithms::is_cycle_UD(Graph &graph)
{
    size_t number_vertixs = graph.get_matrix().size();
    vector<bool> visited(number_vertixs, false);
    vector<bool> in_recursion_stack(number_vertixs, false);
    vector<size_t> path;

    for (size_t i = 0; i < number_vertixs; ++i)
    {
        if (!visited[i])
        {
            if (dfs_UD_cycle_detection(graph, i, visited, in_recursion_stack, path))
            {
                print_cycle(path);
                return true;
            }
        }
    }
    // No cycle found
    cout << "-1" << endl;
    return false;
}

bool Algorithms::isContainsCycle(Graph &graph)
{
    if (graph.isDirectedG())
    {
        return (is_cycle_UD(graph));
    }

    return (is_cycle_D(graph.get_matrix()));
}

string Algorithms::Two_Color_Division(Graph &graph)
{
    vector<int> Group_A;
    vector<int> Group_B;
    unordered_map<int, int> color; // Map to store colors of nodes
    queue<int> Queue;

    // Start BFS traversal from each unvisited node
    for (int i = 0; i < (int)graph.getSize(); ++i)
    {
        if (color.find(i) == color.end())
        { // Unvisited node
            Queue.push(i);
            color[i] = 0; // Assign color 0 to start with

            while (!Queue.empty())
            {
                int curr = Queue.front();
                Queue.pop();
                if (color[curr] == 0)
                {
                    Group_A.push_back(curr);
                }
                else
                {
                    Group_B.push_back(curr);
                }
                // Traverse neighbors of curr

                for (int k = 0; k < graph.get_matrix()[(size_t)curr].size(); k++)
                {
                    if (graph.get_matrix()[(size_t)curr][(size_t)k] != 0)
                    {
                        if (color.find(k) == color.end())
                        {                               // Unvisited neighbor
                            color[k] = 1 - color[curr]; // Assign opposite color
                            Queue.push(k);
                        }
                        else if (color[k] == color[curr])
                        {
                            // If neighbor has same color as curr, not bipartite
                            return "0";
                        }
                    }
                }
            }
        }
    }

    // Construct strings representing sets A and B
    string setA = constructSetString(Group_A);
    string setB = constructSetString(Group_B);

    return "The graph is bipartite: A=" + setA + ", B=" + setB;
}

string Algorithms::constructSetString(const vector<int> &Group)
{
    string setStr = "{";
    for (int node : Group)
    {
        setStr += to_string(node) + ", ";
    }
    if (!setStr.empty())
    {
        setStr.pop_back(); // Remove the last comma
        setStr.pop_back(); // Remove the space
    }
    setStr += "}";
    return setStr;
}

string Algorithms::isBipartite(Graph &graph)
{
    if (!graph.isDirectedG())
    {
        return Two_Color_Division(graph);
    }
    Graph Clique = graph.getClique();
    return Two_Color_Division(Clique);
}

bool Algorithms::bellmanFord_negative_cycle(Graph &graph)
{
    vector<size_t> cycle;
    size_t number_vertixs = graph.getSize();
    size_t source = 0;
    vector<bool> in_path(graph.getSize(), false); // Mark vertices in the current path
    vector<int> dist(number_vertixs, INT_MAX);
    vector<size_t> pred(number_vertixs, 0); // Store predecessors for tracing the cycle
    dist[source] = 0;

    // Relax all edges |V| - 1 times
    for (size_t i = 0; i < number_vertixs - 1; ++i)
    {
        for (size_t j = 0; j < number_vertixs; ++j)
        {
            for (size_t k = 0; k < number_vertixs; ++k)
            {
                relax(j, k,  dist,  pred, graph); 
            }
        }
    }
    // Check for negative cycles
    for (size_t j = 0; j < number_vertixs; ++j)
    {
        for (size_t k = 0; k < number_vertixs; ++k)
        {
            if (graph.get_matrix()[j][k] != 0 && dist[j] != INT_MAX && dist[j] + graph.get_matrix()[j][k] < dist[k])
            {
                // Negative cycle detected
                size_t curr = k;
                while (!in_path[curr])
                {
                    in_path[curr] = true; // Mark the current vertex
                    curr = pred[curr];
                }

                vector<size_t> cycle;
                size_t start = curr;
                do
                {
                    cycle.push_back(curr);
                    curr = pred[curr];
                } while (curr != start);

                printNegativeCycle(cycle);

                return true; // Negative cycle found
            }
        }
    }

    return false; // No negative cycle found
}
void Algorithms::printNegativeCycle(const vector<size_t> &cycle)
{
    cout << "Graph contains negative weight cycle: ";
    for (size_t i = cycle.size() - 1; i > 0; --i)
    {
        cout << cycle[i] << "->";
    }
    cout << cycle[0];
    cout << "->" << cycle[cycle.size() - 1] << endl;
}
void Algorithms::relax(size_t verex1, size_t verex2, vector<int> &dist, vector<size_t> &pred, Graph &graph) {
    if (graph.get_matrix()[verex1][verex2] != 0 && dist[verex1] != INT_MAX && dist[verex1] + graph.get_matrix()[verex1][verex2] < dist[verex2]) {
        dist[verex2] = dist[verex1] + graph.get_matrix()[verex1][verex2];
        pred[verex2] = verex1; // Update predecessor
    }
}
bool Algorithms::negativeCycle(Graph &graph)
{

    return bellmanFord_negative_cycle(graph);
}
