#include "LinkedList.h"
#include "HelperFunctions.h"

LinkedList::LinkedList(){
    root = nullptr;
}

void LinkedList::addNode(int value){
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;
    if (root == nullptr){
        root = newNode;
    }
    else{
        HelperFunctions::addNodeHelper(root->next, newNode);
    }
}