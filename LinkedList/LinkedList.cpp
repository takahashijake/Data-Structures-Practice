#include "LinkedList.h"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList(){
    root = nullptr;
}

template <typename T>
void LinkedList<T>::Append(T value){
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

template <typename T>
void LinkedList<T>::Prepend(T value){
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    newNode->parent = nullptr;
    if (root == nullptr){
        root = newNode;
    }
    else{
        newNode->next = root;
        root = newNode;
        newNode->next->parent = newNode;
    }
    
}

template <typename T>
void LinkedList<T>::printList(){
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

template <typename T>
int LinkedList<T>::getSize(){
    int count = 0;
    Node* current = root;
    while (current != nullptr){
        count++;
        current = current->next;
    }       
    std::cout << "The linked list is " << count << " elements long!" << std::endl;

    return count;
}

template <typename T>
void LinkedList<T>::reverseList(){
    if (root == nullptr){
        throw std::logic_error("Cannot reverse an empty list!");
    }
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

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::searchHelper(T value){
    Node* current = root;
    while (current != nullptr){
        if (current->value == value){
            return current;
        }
    }
    return nullptr;
    /*while (current->value != value){
        current = current->next;
        if (current == nullptr){
           throw std::logic_error("The value does not exist in the Linked List!");
        }
    }*/
    std::cout << "Value of found Node is: " << current->value << std::endl;
    return current;
}

template <typename T>
void LinkedList<T>::search(T value){
    LinkedList::searchHelper(value);
}

template <typename T>
void LinkedList<T>::deleteNode(T value){
    Node* deleteNode = LinkedList::searchHelper(value);
    if (deleteNode == nullptr){
        std::cout << "The value does not exist!" << std::endl;
    }
    if (deleteNode == root){
        deleteNode->next->parent = nullptr;
        root = deleteNode->next;
        delete deleteNode;
    }
    else if (deleteNode == root && deleteNode->next == nullptr){
        delete deleteNode;
        root = nullptr;
    }
    else if (deleteNode->next == nullptr){
        deleteNode->parent->next = nullptr;
        delete deleteNode;
    }
    else{
        Node* temp = deleteNode;
        deleteNode->parent->next = deleteNode->next;
        deleteNode->next->parent = deleteNode->parent;
        delete temp;
    }
}

template <typename T>
LinkedList<T>::~LinkedList(){
    Node* current = root;
    while (current != nullptr){
        Node* temp = current->next;
        delete current;
        current = temp;
    }
    std::cout << "Destructor called successfully!" << std::endl;
}

template <typename T>
void LinkedList<T>::deleteBeginning(){
    if (root == nullptr){
        throw std::logic_error("Cannot delete from an empty list!");
    }
    else if (root != nullptr && root->next == nullptr){
        delete root;
        root = nullptr;
    }
    else{
        root->next->parent = nullptr;
        Node* temp = root->next;
        delete root;
        root = temp;
    }
}

template <typename T>
void LinkedList<T>::deleteEnd(){
    if (root == nullptr){
        throw std::logic_error("Cannot delete from an empty list!");
    }
    else if (root != nullptr && root->next == nullptr){
        delete root;
        root = nullptr;
    }
    else{
        Node* current = root;
        while (current->next != nullptr){
            current = current->next;
        }
        std::cout << "Value of last node is: " << current->value << std::endl;
        current->parent->next = nullptr;
        delete current;
    }
}