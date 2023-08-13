#ifndef _GRAPH_
#define _GRAPH_

#include <stack>
#include <vector>

//Classe que representa o grafo
class Graph {
private:
    int numEdges; //Numero de vertices 
    std::vector<std::vector<int>>adj; //lista adjacencias

    void dfs(int v, bool used[], std::stack<int> &stack);
    void dfsPrint(int v, bool used[]);
    bool isCyclic_util(std::vector<bool> visited, int curr);

public:
    Graph(int n_edges);//Construtor
    

    void addEdge(int a, int b);
    void displayAdjList();
    Graph transposedGraph();
    void kosajuru();
    bool isCyclic();
};

#endif