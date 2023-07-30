#include "graph.hpp"
#include <iostream>
#include <stack>

Graph::Graph(int n_edges) {
    this->numEdges = n_edges;
    this->adj = new std::vector<int>[n_edges];
}

void Graph::dfs1(int v, bool used[], std::stack<int> &stack) {
    used[v] = true;
    for (int u : adj[v]) {
        if (!used[u]) {
            dfs1(u, used, stack);
        }
    }
    stack.push(v);
}

void Graph::dfs(int v, bool used[]) {
    used[v] = true;
    std::cout << v << ' ';
    for (int u : adj[v]) {
        if (!used[u]) {
            dfs(u, used);
        }
    }
}

void Graph::addEdge(int a, int b) {
    if (a < 0 || b < 0 || a >= numEdges || b >= numEdges)
        return;
    this->adj[a].push_back(b);
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
    Graph g(this->numEdges);

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
            dfs1(i, used, stack);
        }
    }

    Graph gt = transposedGraph();

    for (int i = 0; i < numEdges; i++)
        used[i] = false;

    while (!stack.empty()) {
        int v = stack.top();
        stack.pop();

        if (!used[v]) {
            gt.dfs(v, used);
            std::cout << '\n';
        }
    }
}
