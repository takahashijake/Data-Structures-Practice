#include "Graph.h"

int main(){

    UndirectedGraph<int> Graph;

    Graph.addNode(3);
    Graph.addNode(4);
    Graph.addNode(5);
    Graph.addEdge(4, 5);
    Graph.adjacencyList();

    return 0;
}