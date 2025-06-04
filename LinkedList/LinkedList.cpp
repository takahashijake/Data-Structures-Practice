#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(){
    root = nullptr;
}

void LinkedList::addNode(int value){
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    newNode->parent = nullptr;
    if (root == nullptr){
        root = newNode;
    }
    else{
        Node* current = root;
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
        newNode->parent = current;
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

void LinkedList::reverseList(){
    Node* current = root;
    Node* newRoot = nullptr;
    while (current != nullptr){
        Node* next = current->next;
        Node* parent= current->parent;
        current->next = parent;
        current->parent = next;
        newRoot = current;
        current = next;
    }
    root = newRoot;
}