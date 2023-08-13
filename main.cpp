#include "graph.hpp"
#include <iostream>


int main(int argc, char const *argv[]) {
    int v, a;

    std::cout<<"Digite o numero de vertices no grafo" << std::endl;
    std::cin >>v;

    Graph g(v);

    std::cout << "Digite o numero de arestas no grafo"<<std::endl;
    std::cin>>a;

    for(int i=0; i<a; i++){
        int src, dest;
        std::cout << "Digite o vertice de origem e o de destino da aresta "<< i+1 <<std::endl;
        std::cin >> src >>dest;
        g.addEdge(src, dest);

    } 

    g.kosajuru();
    
    std::cout<< std::endl;

    if(g.isCyclic()){
        std::cout << "O grafo tem ciclo" << std::endl;
    }else{
        std::cout << "O grafo nao tem ciclo" << std::endl;
    }
    

    return 0;
}
