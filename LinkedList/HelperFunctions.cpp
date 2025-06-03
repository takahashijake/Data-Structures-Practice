#include "HelperFunctions.h"
#include <iostream>

void HelperFunctions::addNodeHelper(LinkedList::Node* addNode, LinkedList::Node* currentNode){
    if (currentNode == nullptr){
        currentNode = addNode;
    }
    else{
        addNodeHelper(addNode, currentNode->next);
    }
}
