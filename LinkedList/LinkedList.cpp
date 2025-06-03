#include "LinkedList.h"
#include "HelperFunctions.h"
#include <iostream>

LinkedList::LinkedList(){
    root = nullptr;
}

void LinkedList::addNode(int value){
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    if (root == nullptr){
        root = newNode;
    }
    else{
        HelperFunctions::addNodeHelper(newNode, root->next);
    }
}

void LinkedList::printList(){
    Node* current = root; 
    while (current != nullptr){
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}