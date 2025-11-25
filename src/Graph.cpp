#include "Graph.h"

Graph::Graph() {}

void Graph::addPath(const vector<string> &path)
{
    if (path.size() < 2)
        return;

    for (size_t i = 0; i < path.size() - 1; i++)
    {
        const string &u = path[i];
        const string &v = path[i + 1];

        // Directed edge: u → v
        adj[u].push_back(v);

        // DO NOT add v->u   (this is what makes it directed)
        if (!adj.count(v)) adj[v] = {}; 
        // ensures v exists as a node
    }
}

void Graph::dfsUtil(const string &node, unordered_set<string> &visited, vector<string> &result)
{
    visited.insert(node);
    result.push_back(node);

    for (auto &nb : adj[node])
    {
        if (!visited.count(nb))
            dfsUtil(nb, visited, result);
    }
}

vector<string> Graph::dfs(const string &start)
{
    vector<string> result;
    unordered_set<string> visited;

    if (adj.count(start))
        dfsUtil(start, visited, result);

    return result;
}

vector<string> Graph::bfs(const string &start)
{
    vector<string> result;
    if (!adj.count(start))
        return result;

    unordered_set<string> visited;
    queue<string> q;

    q.push(start);
    visited.insert(start);

    while (!q.empty())
    {
        string node = q.front();
        q.pop();
        result.push_back(node);

        for (auto &nb : adj[node])
        {
            if (!visited.count(nb))
            {
                visited.insert(nb);
                q.push(nb);
            }
        }
    }

    return result;
}

vector<string> Graph::shortestPath(const string &src, const string &dest)
{
    vector<string> path;
    if (!adj.count(src) || !adj.count(dest))
        return path;

    unordered_map<string, string> parent;
    unordered_set<string> visited;
    queue<string> q;

    q.push(src);
    visited.insert(src);
    parent[src] = "";

    while (!q.empty())
    {
        string node = q.front();
        q.pop();

        if (node == dest)
            break;

        for (auto &nb : adj[node])
        {
            if (!visited.count(nb))
            {
                visited.insert(nb);
                parent[nb] = node;
                q.push(nb);
            }
        }
    }

    if (!parent.count(dest))
        return {};

    for (string cur = dest; cur != ""; cur = parent[cur])
        path.push_back(cur);

    reverse(path.begin(), path.end());
    return path;
}

void Graph::printGraph()
{
    for (auto &p : adj)
    {
        cout << p.first << " -> ";
        for (auto &nb : p.second)
            cout << nb << " ";
        cout << "\n";
    }
}
