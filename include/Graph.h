#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    Graph();                    // constructor
    void addPath(const vector<string>& path);
    vector<string> bfs(const string&);
    vector<string> dfs(const string&);
    vector<string> shortestPath(const string&, const string&);
    void printGraph();

private:
    unordered_map<string, vector<string>> adj;
    void dfsUtil(const string&, unordered_set<string>&, vector<string>&);
};

#endif
