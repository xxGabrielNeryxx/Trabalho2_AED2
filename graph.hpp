#ifndef _GRAPH_
#define _GRAPH_

#include <stack>
#include <vector>

class Graph {
private:
    int numEdges;
    std::vector<int> *adj;

    void dfs1(int v, bool used[], std::stack<int> &stack);
    void dfs(int v, bool used[]);

public:
    Graph(int n_edges);
    void addEdge(int a, int b);
    void displayAdjList();
    Graph transposedGraph();
    void kosajuru();
};

#endif