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

    public:
        
        UndirectedGraph(){
        
        }

        void addNode(T value){
            Node* newNode = new Node;
            newNode->value = value;
            nodes.push_back(newNode);
        }

        void addEdge(T firstValue, T secondValue){
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

        void adjacencyMatrix(){
            std::cout << " "
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