#ifndef Graph_H
#define Graph_H

#include <vector>
#include <iostream>
#include <climits>

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

        Edge* edgeSearch(std::vector<Edge*> edges, Node* first, Node* second){
            for (int i = 0; i < edges.size(); i++){
                if ((edges[i]->firstNode == first && edges[i]->secondNode == second) || (edges[i]->firstNode == second && edges[i]->secondNode == first)){
                    return edges[i];
                }
            }
            return nullptr;
        }

        bool hasSeen(std::vector<Node*> seenVector, Node* candidate){
            for (int i = 0; i < seenVector.size(); i++){
                if (candidate == seenVector[i]){
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
                secondNode->neighbors.push_back(firstNode);
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
        void DepthFirstSearch(T value){

            Node* sourceNode = nodeSearchHelper(value);
            if (sourceNode == nullptr){
                throw std::logic_error("Node does not exist!");
                return;
            }
            std::cout << "Level 0: " << sourceNode->value << std::endl;
            std::vector<Node*> seen;
            std::vector<Node*> current;
            std::vector<Node*> currentHelp;
            seen.push_back(sourceNode);
            current.push_back(sourceNode);

            int count = 0; 
            if (seen.size() <= nodes.size() && current.empty()){
                count++;
                std::cout << "Level " << count << ": " << std::endl;
                for (int i = 0; i < current.size(); i++){
                    for (int j = 0; j < current[i]->neighbors.size(); j++){
                        if (!hasSeen(seen, current[i]->neighbors[j])){
                            std::cout << current[i]->value << " ";
                            seen.push_back(current[i]->neighbors[j]);
                            currentHelp.push_back(current[i]->neighbors[j]);
                        }
                    }
                }
                std::cout << std::endl;
                current.clear();
                std::cout << "Current size afer current.clear() is: " << current.size() << std::endl;
                for (int i = 0; i < currentHelp.size(); i++){
                    current.push_back(currentHelp[i]);
                }
                currentHelp.clear();

            }

        }


        void PrimsAlgorithm(T value){
            Node* sourceNode = nodeSearchHelper(value);
            if (sourceNode == nullptr){
                throw std::logic_error("Node does not exist!");
            }

            std::vector<Edge*> MST;
            std::vector<Node*> seen;
            seen.push_back(sourceNode);
            for (int i = 0; i < (nodes.size() - 1); i++){
                int minimumEdgeWeight = INT_MAX;
                Edge* currentEdge = nullptr;
                for (int j = 0; j < seen.size(); j++){
                    for (int k = 0; k < (seen[j]->neighbors.size()); k++){
                        if (hasSeen(seen, seen[j]->neighbors[k])){
                            continue;
                        }
                        else{
                            Edge* candidateEdge = edgeSearch(edges, seen[j], seen[j]->neighbors[k]);
                            if (candidateEdge == nullptr){
                                continue;
                            }
                            else{
                                if (candidateEdge->weight <= minimumEdgeWeight){
                                    currentEdge = candidateEdge;
                                    minimumEdgeWeight = candidateEdge->weight;
                                }
                            }
                        }
                    }
                }
                MST.push_back(currentEdge);
                if (!hasSeen(seen, currentEdge->firstNode)){
                    seen.push_back(currentEdge->firstNode);
                }
                else{
                    seen.push_back(currentEdge->secondNode);
                }
            }
            int count = 0;
            /*for (int i = 0; i < MST.size(); i++){
                count = count + MST[i]->weight;
                std::cout << "Edge" << i << ": " << MST[i]->firstNode->value << "->" << MST[i]->secondNode->value << "->" << MST[i]->weight << std::endl;
            }*/
            //std::cout << "Total weight is: " << count << std::endl;

            for (int i = 0; i < MST.size(); i++){
                std::cout << MST[i]->firstNode->value << std::endl;
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
