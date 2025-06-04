#include "LinkedList.h"
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
        Node* current = root;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::printList(){
    if (root == nullptr){
        std::cout << "Cannot print an empty list!" << std::endl;
        return;
    }
    Node* current = root; 
    while (current != nullptr){
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void LinkedList::getSize(){
    int count = 0;
    Node* current = root;
    while (current != nullptr){
        count++;
        current = current->next;
    }       
    std::cout << "The linked list is " << count << " elements long!" << std::endl;
}