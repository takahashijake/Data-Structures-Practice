#include <iostream>
#include "Graph.h"  // Make sure this matches your header filename

int main() {
    // Test Case 1: Simple Linear Graph
    std::cout << "=== Test Case 1: Linear Graph (A-B-C-D) ===" << std::endl;
    UndirectedGraph<std::string> linearGraph;
    
    linearGraph.addNode("A");
    linearGraph.addNode("B");
    linearGraph.addNode("C");
    linearGraph.addNode("D");
    
    linearGraph.addEdge("A", "B", 1);
    linearGraph.addEdge("B", "C", 1);
    linearGraph.addEdge("C", "D", 1);
    
    std::cout << "\nAdjacency List:" << std::endl;
    linearGraph.adjacencyList();
    
    std::cout << "\nBFS from A:" << std::endl;
    linearGraph.BreadthFirstSearch("A");
    
    std::cout << "\nBFS from C:" << std::endl;
    linearGraph.BreadthFirstSearch("C");

    // Test Case 2: Star-shaped Graph
    std::cout << "\n\n=== Test Case 2: Star Graph (Center: X) ===" << std::endl;
    UndirectedGraph<char> starGraph;
    
    starGraph.addNode('X');
    starGraph.addNode('A');
    starGraph.addNode('B');
    starGraph.addNode('C');
    starGraph.addNode('D');
    
    starGraph.addEdge('X', 'A', 1);
    starGraph.addEdge('X', 'B', 1);
    starGraph.addEdge('X', 'C', 1);
    starGraph.addEdge('X', 'D', 1);
    
    std::cout << "\nAdjacency List:" << std::endl;
    starGraph.adjacencyList();
    
    std::cout << "\nBFS from X:" << std::endl;
    starGraph.BreadthFirstSearch('X');
    
    std::cout << "\nBFS from B:" << std::endl;
    starGraph.BreadthFirstSearch('B');

    // Test Case 3: Disconnected Graph
    std::cout << "\n\n=== Test Case 3: Disconnected Graph ===" << std::endl;
    UndirectedGraph<int> disconnectedGraph;
    
    disconnectedGraph.addNode(1);
    disconnectedGraph.addNode(2);
    disconnectedGraph.addNode(3);
    disconnectedGraph.addNode(4);
    
    disconnectedGraph.addEdge(1, 2, 1);
    disconnectedGraph.addEdge(3, 4, 1);
    
    std::cout << "\nAdjacency List:" << std::endl;
    disconnectedGraph.adjacencyList();
    
    std::cout << "\nBFS from 1:" << std::endl;
    disconnectedGraph.BreadthFirstSearch(1);
    
    std::cout << "\nBFS from 3:" << std::endl;
    disconnectedGraph.BreadthFirstSearch(3);

    // Test Case 4: Complex Graph
    std::cout << "\n\n=== Test Case 4: Complex Graph ===" << std::endl;
    UndirectedGraph<std::string> complexGraph;
    
    complexGraph.addNode("A");
    complexGraph.addNode("B");
    complexGraph.addNode("C");
    complexGraph.addNode("D");
    complexGraph.addNode("E");
    complexGraph.addNode("F");
    
    complexGraph.addEdge("A", "B", 1);
    complexGraph.addEdge("A", "C", 1);
    complexGraph.addEdge("B", "D", 1);
    complexGraph.addEdge("C", "E", 1);
    complexGraph.addEdge("D", "E", 1);
    complexGraph.addEdge("D", "F", 1);
    complexGraph.addEdge("E", "F", 1);
    
    std::cout << "\nAdjacency List:" << std::endl;
    complexGraph.adjacencyList();
    
    std::cout << "\nBFS from A:" << std::endl;
    complexGraph.BreadthFirstSearch("A");
    
    std::cout << "\nBFS from F:" << std::endl;
    complexGraph.BreadthFirstSearch("F");

    // Test Case 5: Empty Graph (Should Throw Exception)
    std::cout << "\n\n=== Test Case 5: Empty Graph ===" << std::endl;
    UndirectedGraph<int> emptyGraph;
    
    try {
        std::cout << "Attempting BFS on empty graph..." << std::endl;
        emptyGraph.BreadthFirstSearch(1);
    } catch (const std::logic_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test Case 6: Non-existent Node (Should Throw Exception)
    std::cout << "\n\n=== Test Case 6: Non-existent Node ===" << std::endl;
    UndirectedGraph<char> smallGraph;
    smallGraph.addNode('X');
    
    try {
        std::cout << "Attempting BFS from non-existent node 'Y'..." << std::endl;
        smallGraph.BreadthFirstSearch('Y');
    } catch (const std::logic_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}