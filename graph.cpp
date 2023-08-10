#include "graph.hpp"
#include <iostream>
#include <stack>

Graph::Graph(int n_edges) {
    numEdges = n_edges;
    adj = std::vector<std::vector<int>>(numEdges);
}

void Graph::dfs(int v, bool used[], std::stack<int> &stack) {
    used[v] = true;
    for (int u : adj[v]) {
        if (!used[u]) {
            dfs(u, used, stack);
        }
    }
    stack.push(v);
}

void Graph::dfsPrint(int v, bool used[]) {
    used[v] = true;
    std::cout << v << ' ';
    for (int u : adj[v]) {
        if (!used[u]) {
            dfsPrint(u, used);
        }
    }
}

void Graph::addEdge(int a, int b) {
    if (a < 0 || b < 0 || a >= numEdges || b >= numEdges)
        return;
    adj[a].push_back(b);
}

void Graph::displayAdjList() {
    for (int i = 0; i < numEdges; i++) {
        std::cout << '[' << i << ']' << " -> ";
        for (int vertex : adj[i]) {
            std::cout << vertex << " -> ";
        }
        std::cout << "NULL\n";
    }
}

Graph Graph::transposedGraph() {
    Graph g(numEdges);

    for (int i = 0; i < numEdges; i++) {
        for (int v : adj[i]) {
            g.addEdge(v, i);
        }
    }

    return g;
}

void Graph::kosajuru() {
    std::stack<int> stack;
    bool *used = new bool[numEdges];

    for (int i = 0; i < numEdges; i++)
        used[i] = false;

    for (int i = 0; i < numEdges; i++) {
        if (!used[i]) {
            dfs(i, used, stack);
        }
    }

    Graph gt = transposedGraph();

    for (int i = 0; i < numEdges; i++)
        used[i] = false;

    std::cout << "strongly connected components:\n";

    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        if (!used[v]) {
            gt.dfsPrint(v, used);
            std::cout << '\n';
        }
    }

    delete used;
}

bool Graph::isCyclic_util(std::vector<bool> visited, int curr) {
    if (visited[curr] == true)
        return true;

    visited[curr] = true;
    bool FLAG = false;

    for (int i = 0; i < adj[curr].size(); ++i) {
        FLAG = isCyclic_util(visited, adj[curr][i]);
        if (FLAG == true)
            return true;
    }
    return false;
}

bool Graph::isCyclic() {
    std::vector<bool> visited(numEdges, false);
    bool FLAG = false;
    for (int i = 0; i < numEdges; i++) {
        visited[i] = true;
        for (int j = 0; j < adj[i].size(); j++) {
            FLAG = isCyclic_util(visited, adj[i][j]);
            if (FLAG == true)
                return true;
        }
        visited[i] = false;
    }
    return false;
}
