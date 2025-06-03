#include "HelperFunctions.h"

void HelperFunctions::addNodeHelper(LinkedList::Node* addNode, LinkedList::Node* currentNode){
    if (currentNode->next == nullptr){
        currentNode->next = addNode;
    }
    else{
        HelperFunctions::addNodeHelper(addNode, currentNode->next);
    }
}