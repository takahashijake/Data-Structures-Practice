#ifndef Graph_H
#define Graph_H

#include <vector>
#include <iostream>

template <typename T>
class UndirectedGraph{

    private:
        int numberOfNodes;
        struct Node{
            std::vector<Node*> neighbors; 
            T value;
        };

        struct Edge{
            Node* firstNode;
            Node* secondNode;
            int weight;
        };
        std::vector<Edge*> edges;
        std::vector<Node*> nodes;

        Node* nodeSearchHelper(T value){
            for (int i = 0; i < nodes.size(); i++){
                if (nodes[i]->value == value){
                    return nodes[i];
                }
            }
            return nullptr;
        }

        bool edgeExists(Edge* edge){
            for (int i = 0; i < edges.size(); i++){
                if (edges[i]->firstNode == edge->firstNode && edges[i]->secondNode == edge->secondNode){
                    return true;
                }
            }
            return false;
        }

        bool isNeighbor(Node* node, Node* neighborCandidate){
            for (int i = 0; i < node->neighbors.size(); i++){
                if (node->neighbors[i] == neighborCandidate){
                    return true;
                }
            }
            return false;
        }

        int nodeIndex(Node* node, std::vector<Node*> nodeVector){
            int count = 0;
            for (int i = 0; i < nodeVector.size(); i++){
                if (nodeVector[i] == node){
                    return count;
                }
                count++;
            }
            return -1;
        }

        void vectorShift(std::vector<Node*>& vector, int index){
            if (index > vector.size()){
                throw std::logic_error("Given index is out of bounds!");
            }
            for (int i = index; i < vector.size() - 1; i++){
                vector[i] = vector[i + 1];
            }
            vector.pop_back();
        }


    public:
        
        UndirectedGraph(){
        
        }

        void addNode(T value){
            Node* newNode = new Node;
            newNode->value = value;
            nodes.push_back(newNode);
        }

        void addEdge(T firstValue, T secondValue, int weight){
            Node* firstNode = nodeSearchHelper(firstValue);
            if (firstNode == nullptr){
                throw std::logic_error("Node does not exist!");
            }
            Node* secondNode = nodeSearchHelper(secondValue);
            if (secondNode == nullptr){
                throw std::logic_error("Node does not exist!");
            }

            Edge* newEdge = new Edge;
            newEdge->firstNode = firstNode;
            newEdge->secondNode = secondNode;
            newEdge->weight = weight;
            if (edgeExists(newEdge)){
                throw std::logic_error("Edge already exists!");
            }
            else{
                edges.push_back(newEdge);
                firstNode->neighbors.push_back(secondNode);
            }
        }

        void adjacencyList(){
            for (int i = 0; i < nodes.size(); i++){
                std::cout << nodes[i]->value << ": ";
                if (nodes[i]->neighbors.size() == 0){
                    std::cout << "NULL";
                }
                else{
                    for (int j = 0; j < nodes[i]->neighbors.size(); j++){
                        std::cout << nodes[i]->neighbors[j]->value << " ";
                    }
                }
                std::cout << std::endl;
            }
        }

        void deleteNode(T value){
            Node* deleteNode = nodeSearchHelper(value);
            int indexNode = nodeIndex(deleteNode, nodes);
            vectorShift(nodes, indexNode);

            std::vector<Edge*> newEdges;
            for (int i = 0; i < edges.size(); i++){
                if (edges[i]->firstNode == deleteNode || edges[i]->secondNode == deleteNode){
                    delete edges[i];
                }
                else{
                    newEdges.push_back(edges[i]);
                }
            }
            edges = newEdges;

            for (int j = 0; j < nodes.size(); j++){
                int neighborIndex = nodeIndex(deleteNode, nodes[j]->neighbors);
                if (neighborIndex != -1){
                    vectorShift(nodes[j]->neighbors, neighborIndex);
                }
            }
            edges = newEdges;
            delete deleteNode;

        }

        void adjacencyMatrix(){
            std::cout << "  ";
            for (int i = 0; i < nodes.size(); i++){
                std::cout << nodes[i]->value << " ";
            }
            std::cout << std::endl;
            for (int j = 0; j < nodes.size(); j++){
                std::cout << nodes[j]->value << " ";
                for (int k = 0; k < nodes.size(); k++){
                    if (isNeighbor(nodes[j], nodes[k])){
                        std::cout << "1 ";
                    }
                    else{
                        std::cout << "0 ";
                    }
                }
                std::cout << std::endl;
            }
        }

        ~UndirectedGraph(){
            for (int i = 0; i < nodes.size(); i++){
                delete nodes[i];
            }
            for (int k = 0; k < edges.size(); k++){
                delete edges[k];
            }
        }
};

#endif 
