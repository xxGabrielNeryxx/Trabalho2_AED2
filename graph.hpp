#ifndef _GRAPH_
#define _GRAPH_

#include <stack>
#include <vector>

class Graph {
private:
    int numEdges;
    std::vector<std::vector<int>>adj;

    void dfs(int v, bool used[], std::stack<int> &stack);
    void dfsPrint(int v, bool used[]);
    bool isCyclic_util(std::vector<bool> visited, int curr);

public:
    Graph(int n_edges);
    

    void addEdge(int a, int b);
    void displayAdjList();
    Graph transposedGraph();
    void kosajuru();
    bool isCyclic();
};

#endif