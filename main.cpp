#include "graph.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {

    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    g.kosajuru();

    return 0;
}
