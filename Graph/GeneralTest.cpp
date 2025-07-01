#include "Graph.h" // Assuming your modified DirectedGraph class is in Graph.h
#include <stdexcept> // For catching exceptions

int main() {
    // IMPORTANT: Ensure your Graph.h is updated for a DirectedGraph.
    // Specifically, addEdge should only add the secondNode to the firstNode's neighbors.
    // Example:
    // void addEdge(T firstValue, T secondValue, int weight){
    //     Node* firstNode = nodeSearchHelper(firstValue);
    //     // ... error checks ...
    //     Node* secondNode = nodeSearchHelper(secondValue);
    //     // ... error checks ...
    //
    //     Edge* newEdge = new Edge;
    //     newEdge->firstNode = firstNode;
    //     newEdge->secondNode = secondNode;
    //     newEdge->weight = weight;
    //     // You might want to adjust edgeExists for directed graphs too
    //     // It should only check for (firstNode, secondNode) specifically
    //     if (edgeExists(newEdge)){
    //         throw std::logic_error("Directed Edge already exists!");
    //     }
    //     else{
    //         edges.push_back(newEdge);
    //         firstNode->neighbors.push_back(secondNode); // Only this direction
    //     }
    // }
    UndirectedGraph<char> graph; // Assuming you've renamed UndirectedGraph or adjusted its behavior

    std::cout << "--- Test 1: addNode ---" << std::endl;
    // Test adding nodes
    graph.addNode('A');
    graph.addNode('B');
    graph.addNode('C');
    graph.addNode('D');
    graph.addNode('E');
    std::cout << "Nodes added: A, B, C, D, E" << std::endl;
    std::cout << std::endl;

    std::cout << "--- Test 2: addEdge (Basic) ---" << std::endl;
    // Test adding directed edges
    // Edges are now: A->B, B->C, A->C, C->D, D->E
    try {
        graph.addEdge('A', 'B', 10);
        graph.addEdge('B', 'C', 5);
        graph.addEdge('A', 'C', 15); // A points to C
        graph.addEdge('C', 'D', 7);
        graph.addEdge('D', 'E', 20);
        std::cout << "Directed Edges added: (A->B), (B->C), (A->C), (C->D), (D->E)" << std::endl;
    } catch (const std::logic_error& e) {
        std::cerr << "Error adding directed edge: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 3: adjacencyList (Initial - Directed) ---" << std::endl;
    // Expected output for a DIRECTED graph:
    // A: B C
    // B: C
    // C: D
    // D: E
    // E: NULL
    std::cout << "Adjacency List after initial additions (Directed Graph):" << std::endl;
    graph.adjacencyList();
    std::cout << std::endl;

    std::cout << "--- Test 4: adjacencyMatrix (Initial - Directed) ---" << std::endl;
    // Expected output for a DIRECTED graph (row is source, column is destination):
    //   A B C D E
    // A 0 1 1 0 0  (A points to B, A points to C)
    // B 0 0 1 0 0  (B points to C)
    // C 0 0 0 1 0  (C points to D)
    // D 0 0 0 0 1  (D points to E)
    // E 0 0 0 0 0  (E points to nothing)
    std::cout << "Adjacency Matrix after initial additions (Directed Graph):" << std::endl;
    graph.adjacencyMatrix();
    std::cout << std::endl;

    std::cout << "--- Test 5: addEdge (Error Cases - Directed) ---" << std::endl;
    // Test adding a non-existent node
    try {
        graph.addEdge('A', 'Z', 100);
        std::cout << "Added edge (A->Z) - ERROR: Should have thrown exception." << std::endl;
    } catch (const std::logic_error& e) {
        std::cout << "Successfully caught expected error for non-existent node: " << e.what() << std::endl;
    }

    // Test adding an already existing directed edge (A->B)
    try {
        graph.addEdge('A', 'B', 10);
        std::cout << "Added edge (A->B) again - ERROR: Should have thrown exception." << std::endl;
    } catch (const std::logic_error& e) {
        std::cout << "Successfully caught expected error for existing directed edge: " << e.what() << std::endl;
    }

    // Test adding a reverse edge (B->A) which is now allowed if A->B exists
    // This should NOT throw an error unless B->A specifically already exists
    try {
        graph.addEdge('B', 'A', 20); // B->A is distinct from A->B in a directed graph
        std::cout << "Successfully added reverse edge (B->A)." << std::endl;
    } catch (const std::logic_error& e) {
        std::cout << "Error adding reverse edge (B->A): " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 6: deleteNode (Existing Node - Directed) ---" << std::endl;
    // Test deleting an existing node ('C')
    // This should remove all incoming and outgoing edges for 'C'.
    try {
        graph.deleteNode('C');
        std::cout << "Node 'C' deleted." << std::endl;
    } catch (const std::logic_error& e) {
        std::cerr << "Error deleting node 'C': " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 7: adjacencyList (After Deletion - Directed) ---" << std::endl;
    // Expected output *if deleteNode works correctly and for a directed graph*:
    // A: B
    // B: A (from new edge B->A)
    // D: E
    // E: NULL
    // Node C should be gone. Edges (A->C) and (B->C) and (C->D) should be gone.
    std::cout << "Adjacency List after deleting 'C' (Directed Graph):" << std::endl;
    graph.adjacencyList();
    std::cout << std::endl;

    std::cout << "--- Test 8: adjacencyMatrix (After Deletion - Directed) ---" << std::endl;
    // Expected output *if deleteNode works correctly and for a directed graph*:
    //   A B D E
    // A 0 1 0 0
    // B 1 0 0 0
    // D 0 0 0 1
    // E 0 0 0 0
    std::cout << "Adjacency Matrix after deleting 'C' (Directed Graph):" << std::endl;
    graph.adjacencyMatrix();
    std::cout << std::endl;

    std::cout << "--- Test 9: addEdge (After Deletion, to/from deleted node - Directed) ---" << std::endl;
    // Attempt to add an edge involving the deleted node 'C'
    try {
        graph.addEdge('A', 'C', 100);
        std::cout << "Added edge (A->C) after deleting C - ERROR: Should have thrown exception." << std::endl;
    } catch (const std::logic_error& e) {
        std::cout << "Successfully caught expected error for adding edge to deleted node: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 10: deleteNode (Non-existent Node - Directed) ---" << std::endl;
    // Test deleting a non-existent node
    try {
        graph.deleteNode('Z');
        std::cout << "Node 'Z' deleted - ERROR: Should have handled gracefully (e.g., no change or throw error)." << std::endl;
    } catch (const std::logic_error& e) {
        std::cout << "Successfully caught expected error for non-existent node: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 11: Add more nodes/edges after deletion (Directed) ---" << std::endl;
    // Add more nodes and edges to see if the graph is still functional
    graph.addNode('F');
    graph.addEdge('A', 'F', 25); // A->F
    graph.addEdge('F', 'E', 30); // F->E
    std::cout << "Added node 'F' and directed edges (A->F), (F->E)." << std::endl;
    std::cout << "Adjacency List after more additions (Directed Graph):" << std::endl;
    graph.adjacencyList();
    std::cout << std::endl;

    // Destructor will be called automatically when 'graph' goes out of scope.
    std::cout << "--- End of tests. Destructor called automatically. ---" << std::endl;

    return 0;
}