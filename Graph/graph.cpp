#include <iostream>
#include "Graph.h"

int main(){

    UndirectedGraph <int>myGraph;
    myGraph.addNode(1);
    myGraph.addNode(2);
    myGraph.addNode(3);
    myGraph.addNode(4);
    myGraph.addNode(5);
    myGraph.addNode(6);
    myGraph.addNode(7);

    myGraph.addEdge(1, 2, 7);
    myGraph.addEdge(2, 3, 8);
    myGraph.addEdge(3, 4, 15);
    myGraph.addEdge(4, 5, 123);
    myGraph.addEdge(5, 6, 10);
    myGraph.addEdge(6, 7, 192);

    myGraph.adjacencyMatrix();
    myGraph.BreadthFirstSearch(3);

    return 0;
}