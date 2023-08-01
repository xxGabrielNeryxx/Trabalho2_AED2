#include "graph.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(4, 5);
    g.addEdge(5, 3);


    g.kosajuru();
    
    if(g.isCyclic()){
        std::cout << "The graph has cycle" << std::endl;
    }else{
        std::cout << "The graph has no cycle" << std::endl;
    }
    

    return 0;
}
